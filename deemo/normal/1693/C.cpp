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

const int MAXN = 2e5 + 10;

int n, m;
vector<int> adj[2][MAXN];
int d[MAXN], cnt[MAXN];

void solve() {
    cin >> n >> m;
    while (m--) {
        int a, b; cin >> a >> b, a--, b--;
        adj[0][a].push_back(b);
        adj[1][b].push_back(a);
    }
 
    memset(d, 63, sizeof(d));
    d[n-1] = 0;
    set<pii> st;
    st.insert({0, n-1});
    while (st.size()) {
        int v = st.begin()->S;
        st.erase(st.begin());
        for (int u: adj[1][v]) {
            cnt[u]++;
            int tmp = d[v] + 1 + (int)adj[0][u].size() - cnt[u];
            if (tmp < d[u]) {
                st.erase({d[u], u});
                d[u] = tmp;
                st.insert({d[u], u});
            }
        }
    }
    cout << d[0] << "\n";
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