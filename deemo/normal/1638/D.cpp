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

const int MAXN = 1e3 + 10;

int n, m, a[MAXN][MAXN];

bool vis[MAXN][MAXN];
bool check(int i, int j, int &c) {
    if (i < 0 || j < 0) return false;
    if (i+1>=n || j+1>=m) return false;
    if (vis[i][j]) return false;
    int mn = 1e9, mx = -1e9;
    for (int di = 0; di <= 1; di++)
        for (int dj = 0; dj <= 1; dj++)
            if (a[i+di][j+dj]) {
                mn = min(mn, a[i+di][j+dj]);
                mx = max(mx, a[i+di][j+dj]);
            }
    if (mn != mx)
        return false;
    vis[i][j] = true;
    c = mn;
    return true;
}

vector<pair<pii, int>> ans, vec;
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
 
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j + 1 < m; j++) {
            int temp;
            if (check(i, j, temp))
                vec.push_back({{i, j}, temp});
        }

    while (vec.size()) {
        auto cell = vec.back().F;
        int c = vec.back().S;
        ans.push_back(vec.back());
        vec.pop_back();

        for (int i = cell.F; i <= cell.F+1; i++)
            for (int j = cell.S; j <= cell.S+1; j++)
                a[i][j] = 0;

        for (int i = cell.F-1; i <= cell.F+1; i++)
            for (int j = cell.S-1; j <= cell.S+1; j++) {
                int temp;
                if (check(i, j, temp))
                    vec.push_back({{i, j}, temp});
            }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j]) {
                cout << "-1\n";
                return;
            }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto x: ans)
        cout << x.F.F+1 << " " << x.F.S+1 << " " << x.S << "\n";
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