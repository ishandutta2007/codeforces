#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,kkkkkkkk;
int f[maxn][40];
inline int query(int l,int r){
    int ans=0;
    for (int i=31;i>=0;--i)
    if (f[l][i]<r&&f[l][i]!=0){
        l=f[l][i];
        ans+=(1<<i);
    }
    if (f[l][0]>=r) return ans+1; else return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1,l,r;i<=n;++i){
        scanf("%d%d",&l,&r);
        l++,r++;
        f[l][0]=max(f[l][0],r);
    }
    for (int i=1;i<=maxn-5;++i) f[i][0]=max(f[i][0],f[i-1][0]);

    for (int k=1;k<=31;++k)
        for (int i=1;i<maxn;++i) if (f[i][k-1]!=0) f[i][k]=f[f[i][k-1]][k-1];

    for (int i=1,l,r;i<=m;++i){
        scanf("%d%d",&l,&r);
        l++,r++;
        printf("%d\n",query(l,r));
    }
    return 0;
}