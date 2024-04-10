#include <bits/stdc++.h>
using namespace std;

int l1=1,r1=0;
long long ans;
int n,m;
long long dp[21][100005];
long long kol[100005];
int a[100005];
inline void mv(int l,int r){
    while (r1<r) {
        ++r1;
        ans+=kol[a[r1]]; ++kol[a[r1]];
    }
    while (r1>r) {
        --kol[a[r1]];
        ans-=kol[a[r1]];
        --r1;
    }
    while (l1<l) {
        --kol[a[l1]];
        ans-=kol[a[l1]];
        ++l1;
    }
    while (l1>l) {
        --l1;
        ans+=kol[a[l1]]; ++kol[a[l1]];
    }
}
void solve(int x,int l,int r,int ll,int rr){
    if (l>r) return;
    int mid=(l+r)>>1;
    dp[x][mid]=1e15;
    int pos=l;
    for (int i=ll;i<=min(mid,rr);++i) {
        mv(i,mid);
        long long res=dp[x-1][i-1]+ans;
        if (dp[x][mid]>res) {
            dp[x][mid]=res;
            pos=i;
        }
    }
    solve(x,l,mid-1,ll,pos);
    solve(x,mid+1,r,pos,rr);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>a[i]; dp[0][i]=1e15;
    }
    for (int i=1;i<=m;++i){
        solve(i,1,n,1,n);
    }
    cout<<dp[m][n];
}