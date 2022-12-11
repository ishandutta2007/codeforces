#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,m,need,n1,n2,x[N],y[N],z[N],c1[N],c2[N],f[N],s[N],R[N],ll,rr;bool flag;
bool cmp(int x,int y){return z[x]<z[y];}
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector<int>v[N],Ans;
bool merge(int id){
    int fx=find(x[id]),fy=find(y[id]);
    if(fx==fy)return 0;
    if(flag)Ans.push_back(id);
    if(s[fx]>s[fy])swap(fx,fy);
    f[fx]=fy;s[fy]+=s[fx];return 1;
}
int main(){
    scanf("%d%d%d",&n,&m,&need);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
        (x[i]==1||y[i]==1?c1[++n1]:c2[++n2])=i;
    }
    sort(c1+1,c1+n1+1,cmp);sort(c2+1,c2+n2+1,cmp);
    int l=-5e8,r=5e8,ans=-1e9;
    while(l<=r){
        int mid=(l+r)>>1,i=1,j=1,now=0;
        for(int k=1;k<=n;k++)f[k]=k,s[k]=1;
        while(i<=n1||j<=n2)
            if(i>n1||(j<=n2&&z[c2[j]]<z[c1[i]]+mid))merge(c2[j++]);
            else now+=merge(c1[i++]);
        if(now>=need)ans=mid,l=mid+1;
        else r=mid-1;
    }
    if(ans==-1e9)puts("-1");
    for(int i=1;i<=n1;i++)z[c1[i]]+=ans;
    int i=1,j=1,now=0;
    for(int k=1;k<=n;k++)f[k]=k,s[k]=1;
    for(int k=-1e9;i<=n1||j<=n2;){
        if(i>n1||(j<=n2&&z[c2[j]]<=z[c1[i]])){
            if(z[c2[j]]!=k)k=z[c2[j]];
            merge(c2[j++]);
        }
        else{
            if(z[c1[i]]!=k)k=z[c1[i]];
            if(merge(c1[i])){
                if(k>=1&&k<=1e5)v[k].push_back(c1[i]);
                now++;
            }
            i++;
        }
    }
    ll=now;now=0;i=j=1;if(ll>need)puts("-1"),exit(0);
    for(int k=1;k<=n;k++)f[k]=k,s[k]=1;
    for(int k=-1e9;i<=n1||j<=n2;){
        if(i>n1||(j<=n2&&z[c2[j]]<z[c1[i]])){
            if(z[c2[j]]!=k){
                if(k>=1&&k<=1e5)R[k]=now;
                k=z[c2[j]];if(k>=1&&k<=1e5)R[k]=1e9;
            }
            merge(c2[j++]);
        }
        else{
            if(z[c1[i]]!=k){
                if(k>=1&&k<=1e5)R[k]=now;
                k=z[c1[i]];if(k>=1&&k<=1e5)R[k]=1e9;
            }
            now+=merge(c1[i++]);
        }
    }
    rr=now;now=0;i=j=1;flag=1;
    for(int k=1;k<=1e5;k++)R[k]=max(0,rr-R[k]);
    for(int k=1;k<=n;k++)f[k]=k,s[k]=1;
    for(int k=-1e9;i<=n1&&j<=n2;){
        k=min(z[c1[i]],z[c2[j]]);
        if(k<1||k>1e5){
            while(i<=n1&&z[c1[i]]==k)
                now+=merge(c1[i++]);
        }
        else{
            for(int l=0;l<v[k].size();l++)now+=merge(v[k][l]);
            while(now+R[k]<need)now+=merge(c1[i++]);
            while(j<=n2&&z[c2[j]]==k)merge(c2[j++]);
            while(i<=n1&&z[c1[i]]==k)now+=merge(c1[i++]);
        }
    }
    while(i<=n1)now+=merge(c1[i++]);
    while(j<=n2)merge(c2[j++]);
    printf("%d\n",n-1);
    for(int i=0;i<Ans.size();i++)printf("%d ",Ans[i]);
    return 0;
}