#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e6 + 10;

int n, q;
ll col[MAXN], fen[MAXN];
set<pii> st;

void addFen(int v, ll val) {
    for (; v < MAXN; v += v&-v)
        fen[v] += val;
}

ll getFen(int v) {
    ll res = 0;
    for (; v; v-=v&-v)
        res += fen[v];
    return res;
}

void split(int pos) {
    if (pos >= n) return;
    auto it = st.upper_bound(make_pair(pos + 1, -1));
    it--;
    if (it->F == pos) return;
    
    int l = it->F;
    int c = it->S;
    st.erase(it);
    st.insert({l, c});
    st.insert({pos, c});
}

void add_range(int l, int r, ll val) {
    addFen(l+1, val);
    addFen(r+1, -val);
}

void solve() {
    cin >> n >> q;
    st.insert({0, 1});
    while (q--) {
        string op; cin >> op;
        if (op[0] == 'C') {
            int l, r, c; cin >> l >> r >> c, l--;
            split(l);
            split(r);
            auto it = st.lower_bound(make_pair(l, -1));
            while (it != st.end() && it->F != r) {
                auto next = it;
                next++;
                auto l = it->F;
                auto prev_c = it->S;
                st.erase(it);
                if (prev_c != c) {
                    int r = next == st.end()? n: next->F;
                    add_range(l, r, col[prev_c] - col[c]);
                }

                it = next;
            }
            st.insert({l, c});
        } else if (op[0] == 'A') {
            int c; ll x; cin >> c >> x;
            col[c] += x;
        } else {
            int v; cin >> v;
            auto it = st.upper_bound(make_pair(v, -1));
            it--;
            cout << getFen(v) + col[it->S] << "\n";
        }
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}