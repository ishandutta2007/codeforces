#include <bits/stdc++.h>
using namespace std;



int n,k;
long double t[200005];
long double dp[2][200005];
long double s[200005],pref[200005],rev[200005];
inline long double get(int l,int r){
    long double res=pref[r]-pref[l-1]-(s[l-1])*(rev[r]-rev[l-1]);
    return res;
}
inline void solve(int x,int l,int r,int ll,int rr){
    if (l>r || ll>rr) return;
    int mid=(l+r)>>1;
    int pos=ll;
    for (int i=ll;i<=min(mid,rr);++i){
        long double res2=get(i,mid)+dp[1-x][i-1];
        if (res2<dp[x][mid]) {
            dp[x][mid]=res2;
            pos=i;
        }
    }
    solve(x,l,mid-1,ll,pos);
    solve(x,mid+1,r,pos,rr);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>t[i];
    for (int i=1;i<=n;++i) {
        s[i]=s[i-1]+t[i];
        rev[i]=(rev[i-1]+1.0/t[i]);
        pref[i]=pref[i-1]+s[i]/t[i];
    }
    for (int i=0;i<=n;++i)
        dp[0][i]=1e18;
    dp[0][0]=0;
    int x=0,y=1;
    for (int i=1;i<=k;++i) {
        swap(x,y);
        for (int j=0;j<=n;++j)
            dp[x][j]=1e18;
        solve(x,1,n,1,n);
    }
    cout<<fixed<<setprecision(10)<<dp[x][n];
}