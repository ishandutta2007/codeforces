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

int h,w,n;
map<pii,int> m[1<<18];
vector<vi> bar;

void ins(int pos, int hei, int val) {
    for (int p = pos^(1<<17); p > 0; p >>= 1)
        m[p][{hei,pos}] = val;
}

vector<pii> query (int l, int r, int mx) {
    r++;
    vector<pii> ret;
    for (l ^= (1<<17), r ^=(1<<17); l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            for (auto it = m[l].begin(); it != m[l].end(); it ++) {
                if (it->f.f <= mx) ret.pb(it->f);
                else break;
            }
            l++;
        }
        if (r&1) {
            r--;
            for (auto it = m[r].begin(); it != m[r].end(); it ++) {
                if (it->f.f <= mx) ret.pb(it->f);
                else break;
            }
        }
    }
    return ret;
}

int del(int pos, int hei) {
    int p = pos^(1<<17);
    int ret = m[p][{hei,pos}];
    for (; p > 0; p >>= 1)
        m[p].erase({hei,pos});
    return ret;
}

void process(vi a) {
    vector<pii> z = query(a[1],a[2],a[0]+a[3]);
    int t = 0;
    for (pii a: z) t = (t+del(a.s,a.f)) % MOD;
    if (t == 0) return;
    
    if (a[1] == 0) ins(a[2]+1,a[0],(2*t) % MOD);
    else if (a[2] == w-1) ins(a[1]-1,a[0],(2*t) % MOD);
    else {
        ins(a[1]-1,a[0],t);
        ins(a[2]+1,a[0],t);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> h >> w >> n;
	F0R(i,w) ins(i,h+1,1);
	F0R(i,n) {
	    int u,l,r,s; cin >> u >> l >> r >> s;
	    l--, r--;
	    bar.pb({u,l,r,s});
	}
	sort(bar.begin(),bar.end()); reverse(bar.begin(),bar.end());
	for (vi a: bar) process(a);
	
	int ans = 0;
	for (pair<pii,int> a: m[1]) ans = (ans+a.s) % MOD;
	cout << ans;
}

// read!
// ll vs. int!