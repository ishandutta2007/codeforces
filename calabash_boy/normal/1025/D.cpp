//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define GCD __gcd
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = -1;
const int MOD = -1;
#define vi vector<int>
#define rep(i,l,r) for (int i=(l);i<(r);i++)
LL pow_mod(LL x,LL y){
    LL ret = 1;
    for (;y;y>>=1){if (y&1) ret = ret*x%MOD;x = x*x%MOD;}
    return ret;
}
vi a;
int n;
vector<vector<vector<bool> > > vis,ans;
bool dfs(int k1,int k2,int k3){
    if (k1 > k2) return true;
    else if (vis[k1][k2][k3])return ans[k1][k2][k3];
    else{
        vis[k1][k2][k3] = true;
        for (int i = k1; i <= k2; i++) {
            if (k3 == 0 && k1 - 1 >= 1) {
                if(GCD(a[k1 - 1], a[i]) == 1)continue;
            }
            if (k3 == 1 && k2 + 1 <= n) {
                if ( GCD(a[k2 + 1], a[i]) == 1)continue;
            }
            if (dfs(k1, i - 1, 1) && dfs(i + 1, k2, 0)) {
                ans[k1][k2][k3] = true;
                return ans[k1][k2][k3];
            }
        }
        return false;
    }
    
}
void input(){
    cin >> n;
    a.resize(n+1);
    vis.resize(n+1);
    ans.resize(n+1);
    for (int i=0;i<n+1;i++){
        vis[i].resize(n+1);
        ans[i].resize(n+1);
        for (int j=0;j<n+1;j++){
            vis[i][j].resize(2);
            ans[i][j].resize(2);
            for (int k=0;k<2;k++){
                vis[i][j][k] = ans[i][j][k] = false;
            }
        }
    }
    rep(i,1,n+1) cin >> a[i];
    sort(a.begin()+1,a.end());
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    input();
    if (dfs(1,n,0)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}