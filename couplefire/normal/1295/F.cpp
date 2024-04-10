#include <bits/stdc++.h>
using namespace std;
#define MAXN 55
#define MOD 998244353

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int ckmin(int &a, int b){return (b<a)?a=b:a;}
int ckmax(int &a, int b){return (b>a)?a=b:b;}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inv(int n){
    int x, y;
    int g = gcd(n,MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

int dp[MAXN][2*MAXN];
vector<int> good;
pair<int, int> segs[MAXN];
int n, m;
int tot = 1;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        int l, r; cin >> l >> r; --l;
        segs[i] = {l, r};
        grow(tot, r-l);
        good.push_back(l); good.push_back(r);
    }
    sort(good.begin(), good.end());
    good.erase(unique(good.begin(), good.end()), good.end());
    m = good.size();
    reverse(segs, segs+n);
    for(int i = 0; i<m; i++) if(good[i] > segs[0].first) dp[0][i] = min(good[i], segs[0].second)-segs[0].first;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<m; j++){
            int cur = 1;
            for(int k = i; k>=0; k--){
                if(j != 0) inc(dp[i][j], mul(cur, dp[k][j-1]));
                if(good[j] <= segs[k].first || good[j-1] >= segs[k].second){cur = 0; break;}
                assert(j > 0);
                int cnt = i-k+1;
                grow(cur, (good[j]-good[j-1]-1+cnt));
                grow(cur, inv(cnt));
            }
            inc(dp[i][j], cur);
        }
    }
    // cout << dp[1][3] << endl;
    cout << mul(dp[n-1][m-1], inv(tot)) << endl;
}