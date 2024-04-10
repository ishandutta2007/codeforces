// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

int l[1000006];
int p[1000006];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    rep1(i, n) {
    	int v; cin >> v;
    	l[i] = p[v];
    	p[v] = i;
    }
    ll ans = 0;
    rep1(i, n) ans += 1ll * (i - l[i]) * (n - i + 1);
    ans = 2 * ans - n;
    long double k = ans;
    k /= (1.L*n)*n;
    cout << fixed << setprecision(18) << k << endl;
}