#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200087, logN = 17, K = 350;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ta;
    cin >> ta;
    string t = "abacaba";
    auto check = [&](string s) {
    	int cnt = 0, n = s.length();
    	fop (i,0,n) if (i + 7 <= n) {
    		bool is = true;
			fop (j,i,i + 7) {
    			if (s[j] != t[j - i]) is = false;
			}
			cnt += is;
		}
		return cnt;
	};
    while (ta--) {
    	int n;
    	string s;
    	cin >> n >> s;
    	string ans = "NO\n";
    	int cnt = check(s);
		if (cnt > 1) {
			cout << ans;
			continue;
		} else if (cnt == 1) {
			fop (i,0,n) if (s[i] == '?') s[i] = 'd';
			cout << "YES\n" << s << endl;
			continue;
		} else {
	    	FOP (i,n,0) if (i + 7 <= n) {
	    		bool is = true;
				fop (j,i,i + 7) {
	    			if (s[j] != '?' && s[j] != t[j - i]) {
	    				is = false;
					}
				}
				if (is) {
					string tmp = s;
					fop (j,0,s.length()) {
						if (tmp[j] == '?') {
							tmp[j] = 'd';
						}
					}
					fop (j,i,i + 7) {
						tmp[j] = t[j - i];
					}
					if (check(tmp) == 1) {
						ans = tmp;
						break;
					}
				}
			}
		}
		if (ans != "NO\n") {
			cout << "YES\n" << ans << endl; 
		} else {
			cout << ans;
		}
	}
}