#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MAXN = 1e3 + 10;

int n, m;
vector<int> vec, sec;
vector<pii> ans;
int mt[2][MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];

bool dfs(int v) {
    if (vis[v])
        return false;
    vis[v] = true;

    for (int u: adj[v])
        if (mt[1][u] == -1 || dfs(mt[1][u])) {
            mt[0][v] = u;
            mt[1][u] = v;
            return true;
        }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (t+1+t > m) {
            cout << "-1\n";
            return;
        }
        if (3 * t > m)
            vec.push_back(t);
        else
            sec.push_back(t);
    }

    memset(mt, -1, sizeof(mt));
    for (int i = 0; i < vec.size(); i++)
        for (int j = 0; j < sec.size(); j++)
            if (vec[i] % sec[j] == 0 && vec[i]*2 + sec[j] <= m)
                adj[i].push_back(j);

    bool changed = true;
    int f = 0;
    while (changed) {
        changed = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < vec.size(); i++)
            if (!vis[i] && mt[0][i] == -1) {
                int x = dfs(i);
                if (x)
                    changed = true, f += x;
            }
    }
    if (f != vec.size()) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < vec.size(); i++)
        ans.push_back({vec[i]*2 + sec[mt[0][i]], vec[i]+sec[mt[0][i]]});
    for (int j = 0; j < sec.size(); j++)
        if (mt[1][j] == -1)
            ans.push_back({sec[j]*3, sec[j]*2});


    cout << ans.size() << "\n";
    for (auto x: ans)
        cout << x.F << " " << x.S << "\n";
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