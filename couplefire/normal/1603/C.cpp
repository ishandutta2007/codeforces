#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int N = 100005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, arr[N];
vector<array<int, 3>> stuff[2]; 
vector<int> dp[2];

void solve(){
    cin >> n; int ans = 0;
    for(int i = 0; i<n; ++i)
        cin >> arr[i];
    for(int i = 0, x = 0, j, k; i<n; ++i, x^=1){
        stuff[x].clear(); dp[x].clear();
        for(j = 1; j<=n; ++j){
            int hi = (arr[i]%j==0?arr[i]/j:arr[i]/j-1);
            int lo = arr[i]/(j+1)+1;
            if(arr[i]/lo!=j || arr[i]/hi!=j) break;
            stuff[x].push_back({j, j+(arr[i]%lo!=0), lo-1});
            if(stuff[x].back()[1]!=j+(arr[i]%hi!=0))
                stuff[x].push_back({j, j+(arr[i]%hi!=0), hi-1}), swap(stuff[x][(int)stuff[x].size()-2], stuff[x][(int)stuff[x].size()-1]);
        }
        for(j = arr[i]/j; j>=1; --j) stuff[x].push_back({arr[i]/j, arr[i]/j+(arr[i]%j!=0), j-1});
        dp[x].resize(stuff[x].size());
        for(int j = 0, k = 0; j<(int)dp[x].size(); ++j){
            if(i==0) {dp[x][j] = stuff[x][j][2]; continue;}
            while(k<(int)stuff[x^1].size()-1 && stuff[x^1][k+1][1]<=stuff[x][j][0]) ++k;
            dp[x][j] = add(dp[x^1][k], mul(i+1, stuff[x][j][2]));
        } inc(ans, dp[x].back());
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}