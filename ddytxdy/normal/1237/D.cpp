#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int n,a[N],b[N],c1[N],cnt1,p[N],c2[N],cnt2,f[N],len[N];
void cmin(int &x,int y){y<x?x=y:0;}
void add(int x,int y){for(;x<=n;x+=x&-x)cmin(f[x],y);}
int ask(int x){int z=1e9;for(;x;x-=x&-x)cmin(z,f[x]);return z;}
multiset<int>s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=(a[i]+1)>>1;
    for(int i=1;i<=n;i++)c1[++cnt1]=a[i],c2[++cnt2]=b[i];
    sort(c1+1,c1+cnt1+1);cnt1=unique(c1+1,c1+cnt1+1)-c1-1;
    sort(c2+1,c2+cnt2+1);cnt2=unique(c2+1,c2+cnt2+1)-c2-1;
    for(int i=0,j=1;j<=cnt2;j++){
        while(i<cnt1&&c1[i+1]<c2[j])i++;
        p[j]=i;
    }
    memset(f,0x3f,sizeof(f));
    if(!p[cnt2]){for(int i=1;i<=n;i++)printf("-1 ");return 0;}
    for(int i=1;i<=n;i++)a[i]=lower_bound(c1+1,c1+cnt1+1,a[i])-c1;
    for(int i=1;i<=n;i++)b[i]=lower_bound(c2+1,c2+cnt2+1,b[i])-c2;
    for(int i=1;i<n;i++)add(a[i],n+i);
    for(int i=n;i;i--)len[i]=ask(p[b[i]])-i,add(a[i],i);
    for(int i=1;i<=n;i++)s.insert(len[i]+i-1);
    for(int i=1;i<=n;i++){
        printf("%d ",*s.begin()-i+1);
        s.erase(s.find(len[i]+i-1));s.insert(len[i]+i-1+n);
    }
    return 0;
}