#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

const int MAXN = 5e5 + 10;

int n, m, k;
int x[MAXN], sz;

map<pii, vector<pair<pii, int>>> ladders;
map<pii, ll> ans;
pii sec[MAXN];

void solve() {
    sz = 0;
    ladders.clear();
    ans.clear();
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> x[i];
    sec[sz++] = {0, 0};
    sec[sz++] = {n-1, m-1};
    for (int i = 0; i < k; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d, a--, b--, c--, d--;
        int h; cin >> h;
        pii p = {a, b};
        pii q = {c, d};
        sec[sz++] = p;
        sec[sz++] = q;
        ladders[p].push_back({q, h});
    }
    sort(sec, sec + sz);
    sz = unique(sec, sec + sz) - sec;
    ans[{n-1, m-1}] = 0;
    for (int r = sz-1; ~r;) {
        int l = r;
        while (l && sec[l-1].first == sec[l].first) l--;
        for (int i = l; i <= r; i++)
            if (!ans.count(sec[i])) ans[sec[i]] = 1e18;
        for (int i = r; i >= l; i--) {
            pii p = sec[i];
            for (auto ld: ladders[p]) {
                auto q = ld.first;
                auto h = ld.second;
                ans[p] = min(ans[p], ans[q] - h);
            }
            if (i + 1 <= r)
                ans[p] = min(ans[p], ans[sec[i+1]] + 1ll * (sec[i+1].second - p.second) * x[p.first]);
        }
        for (int i = l+1; i <= r; i++) {
            pii p = sec[i];
            ans[p] = min(ans[p], ans[sec[i-1]] + 1ll * (p.second - sec[i-1].second) * x[p.first]);
        }
        r = l-1;
    }
    if (ans[{0, 0}] > 1e16)
        cout << "NO ESCAPE\n";
    else
        cout << ans[{0, 0}] << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}