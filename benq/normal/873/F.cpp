// https://github.com/SuprDewd/T-414-AFLV/blob/master/11_strings/aflv_11_strings.pdf
// https://open.kattis.com/problems/suffixsorting

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

struct suffix_array {
    int N;
    vector<vi> P;
    vector<pair<pii,int>> L;
    vi idx;
    string str;
    
    suffix_array(string _str) {
        str = _str; N = str.length();
        P.pb(vi(N)); L.resize(N);
        F0R(i,N) P[0][i] = str[i];
        
        for (int stp = 1, cnt = 1; cnt < N; stp ++, cnt *= 2) {
            P.pb(vi(N));
            F0R(i,N) L[i] = {{P[stp-1][i],i+cnt < N ? P[stp-1][i+cnt] : -1},i};
            sort(L.begin(),L.end());
            F0R(i,N) {
                if (i && L[i].f == L[i-1].f) P[stp][L[i].s] = P[stp][L[i-1].s];
                else P[stp][L[i].s] = i;
            }
        }
        
        idx.resize(N);
        F0R(i,P[P.size()-1].size()) idx[P[P.size()-1][i]] = i;
    }
    
    int lcp(int x, int y) {
        int res = 0;
        if (x == y) return N-x;
        for (int k = P.size() - 1; k >= 0 && x < N && y < N; k--) {
            if (P[k][x] == P[k][y]) {
                x += 1 << k;
                y += 1 << k;
                res += 1 << k;
            }
        }
        return res;
    }
};

int n;
ll ans = 0;
string S, forbid;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> S >> forbid;
	reverse(S.begin(),S.end()), reverse(forbid.begin(),forbid.end());
	
	suffix_array sa = suffix_array(S);
	vi ne;
	F0R(i,n) if (forbid[sa.idx[i]] == '0') {
	    ne.pb(sa.idx[i]);
	    ans = max(ans,(ll)n-sa.idx[i]);
	}
	
	vector<pii> tmp; 
	F0R(i,sz(ne)-1) {
	    tmp.pb({sa.lcp(ne[i],ne[i+1]),i});
	}
	sort(tmp.begin(),tmp.end());
	set<int> z; z.insert(-1), z.insert(sz(ne)-1);
	for (auto a: tmp) {
	    int x = *z.lb(a.s), y = *prev(z.lb(a.s));
	    ans = max(ans,((ll)x-y)*a.f);
	    z.insert(a.s);
	}
	cout << ans;
}

// read!
// ll vs. int!