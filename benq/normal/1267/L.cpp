#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ook order_of_key
#define fbo find_by_order

using namespace std;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define f first
#define s second
#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;

int n,l,k;
str res[1000];
int cnt[26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l >> k;
	str s; cin >> s;
	trav(c,s) cnt[c-'a']++;
	F0R(i,n) F0R(j,l) res[i] += '.';
	int L = 0, R = k-1;
	int lst = 0;
	F0R(j,l) {
		FOR(z,L,R+1) {
			while (!cnt[lst]) {
				lst ++;
				L = z;
			}
			cnt[lst] --;
			res[z][j] = char('a'+lst);
		}
	}
	// exit(0);
	F0R(i,n) F0R(j,l) if (res[i][j] == '.') {
		while (!cnt[lst]) lst ++;
		cnt[lst] --; res[i][j] = char('a'+lst);
	}
	F0R(i,n) cout << res[i] << "\n";
}