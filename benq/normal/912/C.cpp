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
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const int MX = 100000;

ll n,m,bou,inc,dam;
int mx[MX], st[MX], regen[MX];
vector<pii> upd[MX];
vector<pii> ev;
ll ans = 0;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> bou >> inc >> dam;
	
	F0R(i,n) {
	    cin >> mx[i] >> st[i] >> regen[i];
	    upd[i].pb({0,st[i]});
	} // OK
	
	F0R(i,m) {
	    int ti, en, he; cin >> ti >> en >> he;
	    upd[en-1].pb({ti,he});
	} // OK
	
	F0R(i,n) {
	    sort(all(upd[i]));
	    F0R(j,sz(upd[i])) {
	        if (upd[i][j].s <= dam) {
	            int need;
	            if (regen[i] != 0 && mx[i] > dam) need = upd[i][j].f+(dam-upd[i][j].s)/regen[i]+1;
	            else need = 2*MOD;
	            
	            if (j != sz(upd[i])-1) need = min(need,upd[i][j+1].f);
	            else {
	                if (need == 2*MOD && inc > 0) {
	                    cout << -1;
	                    return 0;
	                }
	            }
	            ev.pb({upd[i][j].f,1});
	            ev.pb({need,-1});
	        } 
	    }
	}
	
	sort(all(ev));
	int cur = 0;
	for (int i = 0; i < sz(ev);) {
	    int I = i;
	    int CUR = cur;
	    while (i < sz(ev) && ev[I].f == ev[i].f) {
	        cur += ev[i].s;
	        i ++;
	    }
	    ans = max(ans,cur*(bou+inc*ev[I].f));
	    ans = max(ans,CUR*(bou+inc*(ev[I].f-1)));
	}
	cout << ans;
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!