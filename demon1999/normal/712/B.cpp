#include <bits/stdc++.h>
 
using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const ll mod = int(1e9) + 7, pq = 2, szz = 65536, ma = szz, szz1 = 8;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}
 
ll n;
vector<ll> a, b;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
    string s;
    cin >> s;
    ll k1 = 0, k2 = 0;
    forn (i, sz(s)) {
    	if (s[i] == 'L') k1++;
    	if (s[i] == 'R') k1--;
    	if (s[i] == 'U') k2++;
    	if (s[i] == 'D') k2--;
    }
    if (sz(s) % 2) {
    	cout << "-1";
    	re 0;
    }
    k1 = abs(k1), k2 = abs(k2);
    ll ans = k1 / 2 + k2 / 2 + k1 % 2;
    cout << ans;
	re 0;
}