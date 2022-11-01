#include <bits/stdc++.h>
  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define tm tmmm
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7, p = 239;
const int ma = 2 * 1024;
 
int n, k;
vector<int> a;
vector<string> ss;
int main() {
    //iostream::sync_with_stdio(0);
    //freopen("a.in", "r", stdin);
    cin >> n >> k;
    forn (i, 26) {
    	forn (j, 26) {
    		string s = "";
    		s += char('A' + i);
    		s += char('a' + j);
    		ss.push_back(s);
    	}
    }
    //cout << sz(ss) << "\n";
    forn (i, k - 1)
    	a.push_back(i);
    forn (i, n - k + 1) {
    	string s;
    	cin >> s;
    	if (s == "NO")
    		a.push_back(a[sz(a) - k + 1]);
    	else {
    		vector<int> ok(k, 0);
    		for (int pos = sz(a) - k + 1; pos < sz(a); pos++)
    			ok[a[pos]]++;
    		forn (i, k)
    			if (ok[i] == 0) {
    				a.push_back(i);
    				break;
    			}
    	}
    }
    forn (i, n)
    	cout << ss[a[i]] << " ";
    cout << "\n";
}