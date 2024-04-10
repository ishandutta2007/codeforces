#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int N = 200005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int n, s[N], psum[N], dp[N], ans = 1;
pair<int, int> arr[N];

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> arr[i].x >> arr[i].y >> s[i];
    for(int i = 1; i<=n; i++){
        dp[i] = (arr[i].x-arr[i].y)%MOD;
        int id = lower_bound(arr+1, arr+n+1, make_pair(arr[i].y, -1))-arr;
        inc(dp[i], sub(psum[i-1], psum[id-1]));
        psum[i] = add(psum[i-1], dp[i]);
    }
    for(int i = 1; i<=n; i++){
        inc(ans, (arr[i].x-arr[i-1].x)%MOD);
        if(s[i]) inc(ans, dp[i]);
    }
    cout << ans << '\n';
}