#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n;
vector<string> v[2], bad[2], ran[2];
map<string,int> z;
map<int,int> todo[2];
vector<string> ans;
string tmp;

string gen() {
    while (1) {
        string s = "";
        F0R(i,6) s += char('a'+rand()%26);
        if (!z.count(s)) return s;
    }
}

int cat(string s, int t) {
    for (char c: s) if (!('0' <= c && c <= '9')) return 2;
    if (s[0] == '0') return 2;
    
    int z = stoi(s);
    if (1 <= z && z <= v[0].size()) return t == 1;
    if (z > v[0].size() && z <= n) return t == 0;
    return 2;
}

int getnex(int t) {
    int x = todo[t].begin()->f;
    todo[t].erase(todo[t].begin());
    return x;
}

void solve() {
    while (bad[0].size() || bad[1].size()) {
        if (bad[0].size() && todo[0].size()) {
            ans.pb("move "+bad[0][bad[0].size()-1]+" "+to_string(getnex(0)));
            todo[1][stoi(bad[0][bad[0].size()-1])] = 1;
            bad[0].erase(bad[0].end()-1);
        } else if (bad[1].size() && todo[1].size()) {
            ans.pb("move "+bad[1][bad[1].size()-1]+" "+to_string(getnex(1)));
            todo[0][stoi(bad[1][bad[1].size()-1])] = 1;
            bad[1].erase(bad[1].end()-1);
        } else { 
            ans.pb("move "+bad[0][bad[0].size()-1]+" "+tmp);
            ans.pb("move "+bad[1][bad[1].size()-1]+" "+bad[0][bad[0].size()-1]);
            F0Rd(i,bad[1].size()-1) {
                ans.pb("move "+bad[0][i]+" "+bad[1][i+1]);
                ans.pb("move "+bad[1][i]+" "+bad[0][i]);
            }
            ans.pb("move "+tmp+" "+bad[1][0]);
            bad[0].clear(), bad[1].clear();
        }
    }
    while (ran[0].size()) {
        ans.pb("move "+ran[0][ran[0].size()-1]+" "+to_string(getnex(0)));
        ran[0].erase(ran[0].end()-1);
    }
    while (ran[1].size()) {
        ans.pb("move "+ran[1][ran[1].size()-1]+" "+to_string(getnex(1)));
        ran[1].erase(ran[1].end()-1);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    string s; cin >> s; int t; cin >> t; t ^= 1;
	    v[t].pb(s); z[s] ++;
	}
	FOR(i,1,v[0].size()+1) todo[0][i] = 1;
	FOR(i,v[0].size()+1,n+1) todo[1][i] = 1;
	F0R(j,2) F0R(i,v[j].size()) {
	    int t = cat(v[j][i],j);
	    if (t == 0) { // OK
	        todo[j].erase(stoi(v[j][i]));
	    } else if (t == 1) { // BAD
	        bad[j].pb(v[j][i]);
	        todo[j^1].erase(stoi(v[j][i]));
	    } else if (t == 2) { // RANDOM
	        ran[j].pb(v[j][i]);
	    }
	}
	tmp = gen();
	solve();
	cout << ans.size() << "\n";
	for (auto a: ans) cout << a << "\n";
}

// read!
// ll vs. int!