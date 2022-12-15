#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],n,m;
vector <long long> v[200005],pre[200005];
pair<int,int> mx[200005][20];
long long mod=1e9+7;
int query(int l,int r){
    int g=log2(r-l+1);
    if(mx[l][g].first>=mx[r-(1<<g)+1][g].first) return mx[l][g].second;
    else return mx[r-(1<<g)+1][g].second;
}
void solve(int l,int r){
    int pos=query(l,r),pl=0,pr=0;
    if(pos>l) pl=query(l,pos-1),solve(l,pos-1);
    if(pos<r) pr=query(pos+1,r),solve(pos+1,r);
    //cout<<l<<" "<<r<<" "<<pos<<endl;
    for(int i=1;i<=m;i++){
        v[pos][i]=1;
        if(pos>l) v[pos][i]*=pre[pl][i-1],v[pos][i]%=mod;
        if(pos<r) v[pos][i]*=pre[pr][i],v[pos][i]%=mod;
        pre[pos][i]=(pre[pos][i-1]+v[pos][i])%mod;
    }
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx[i][0].first=a[i],mx[i][0].second=i,v[i].clear(),pre[i].clear(),v[i].resize(m+5),pre[i].resize(m+5);
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++) {
                if(mx[j][i-1].first>=mx[min(n,j+(1<<(i-1)))][i-1].first) mx[j][i]=mx[j][i-1];
                else mx[j][i]=mx[min(n,j+(1<<(i-1)))][i-1];
            }
        a[0]=a[n+1]=100000;
        solve(1,n);
        printf("%lld\n",pre[query(1,n)][m]);
    }
    return 0;
}