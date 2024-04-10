#include <bits/stdc++.h>
using namespace std;
#define rank rkrkrkrk
const int maxn=100005,maxm=200005,maxN=4200005;
int n,q,a[maxn],s[maxm],sa[maxm],rank[maxm],height[maxm],xx[maxm],yy[maxm],sum[maxm];
struct Chairman_Tree1 {
    int tot,root[maxm],left[maxN],right[maxN],t[maxN];
    void add(int l,int r,int g,int v,int &x,int y) {
        x=++tot;
        t[x]=max(t[y],v);
        if (l==r) return;
        left[x]=left[y];
        right[x]=right[y];
        int mid=(l+r)/2;
        if (g<=mid) add(l,mid,g,v,left[x],left[y]);
        else add(mid+1,r,g,v,right[x],right[y]);
    }
    int getmax(int l,int r,int g,int x) { 
        if (r==g) return t[x];
        int mid=(l+r)/2;
        if (g<=mid) return getmax(l,mid,g,left[x]); 
        return max(t[left[x]],getmax(mid+1,r,g,right[x])); 
    } 
}t1,t2; 
struct Chairman_Tree2 {
    int tot,root[maxm],left[maxN],right[maxN],sum[maxN]; 
    void add(int l,int r,int g,int &x,int y) { 
        x=++tot; sum[x]=sum[y]+1; 
        if (l==r) return; 
        left[x]=left[y]; 
        right[x]=right[y]; 
        int mid=(l+r)/2; 
        if (g<=mid) add(l,mid,g,left[x],left[y]);
        else add(mid+1,r,g,right[x],right[y]); 
    } 
    int getsum(int l,int r,int a,int b,int x) { 
        if (l==a && r==b) return sum[x]; 
        int mid=(l+r)/2;
        if (b<=mid) return getsum(l,mid,a,b,left[x]); 
        if (a>mid) return getsum(mid+1,r,a,b,right[x]); 
        return getsum(l,mid,a,mid,left[x])+getsum(mid+1,r,mid+1,b,right[x]); 
    } 
}T; 
bool cmp(int a,int b) { return s[a]<s[b]; } 
void getsa() {
    memset(xx,255,sizeof(xx)); 
    memset(yy,255,sizeof(yy));
    int i,j,l,p,m,*x=xx,*y=yy,*t;
    for (i=0;i<2*n;i++) sa[i]=i;
    sort(sa,sa+2*n,cmp); 
    for (p=i=1,x[sa[0]]=0;i<2*n;i++) x[sa[i]]=(s[sa[i-1]]==s[sa[i]])?p-1:p++;
    for (l=1,m=p;p<2*n;m=p,l*=2) {
        for (p=0,i=n*2-l;i<n*2;i++) y[p++]=i; 
        for (i=0;i<n*2;i++) if (sa[i]>=l) y[p++]=sa[i]-l; 
        for (i=0;i<m;i++) sum[i]=0; 
        for (i=0;i<2*n;i++) sum[x[y[i]]]++; 
        for (i=1;i<m;i++) sum[i]+=sum[i-1]; 
        for (i=2*n-1;i>=0;i--) sa[--sum[x[y[i]]]]=y[i]; 
        for (t=x,x=y,y=t,x[sa[0]]=0,i=p=1;i<2*n;i++) x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+l]==y[sa[i]+l])?p-1:p++; 
    } 
} 
void geth() {
    int i,j,k=0; 
    for (i=0;i<2*n;i++) rank[sa[i]]=i; 
    for (i=0;i<2*n;height[rank[i++]]=k) { 
        k-=(k>0); 
        if (rank[i]) { 
            for (j=sa[rank[i]-1];s[j+k]==s[i+k];k++); 
        } 
    } 
} 
int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]); 
    for (int i=0;i<n;i++) { 
        s[i]=a[i+1]-a[i];
        s[i+n]=-s[i];
    } 
    s[2*n]=2e9+1;
    getsa(); 
    geth(); 
    for (int i=0;i<2*n;i++) {
        t1.add(0,2*n-1,height[i],i+1,t1.root[i+1],t1.root[i]);
        T.add(1,2*n,sa[i]+1,T.root[i+1],T.root[i]); 
    } 
    for (int i=2*n-1;i>=0;i--) t2.add(0,2*n-1,height[i],2*n-i,t2.root[2*n-i],t2.root[2*n-i-1]); 
    scanf("%d",&q);
    while (q--) {
        int l,r; 
        scanf("%d%d",&l,&r); 
        if (l==r) { 
            printf("%d\n",n-1); 
            continue;
        }
        int L=t1.getmax(0,2*n-1,r-l-1,t1.root[rank[l+n-1]+1]),
            R=2*n-t2.getmax(0,2*n-1,r-l-1,t2.root[2*n-rank[l+n-1]-1]),
            ans=0; 
        if (2*l-r>1) ans=T.getsum(1,2*n,1,2*l-r-1,T.root[R])-T.getsum(1,2*n,1,2*l-r-1,T.root[L-1]);
        if (2*r-l<n) ans+=T.getsum(1,2*n,r+1,n-r+l,T.root[R])-T.getsum(1,2*n,r+1,n-r+l,T.root[L-1]); 
        printf("%d\n",ans);
    } 
    return 0; 
}