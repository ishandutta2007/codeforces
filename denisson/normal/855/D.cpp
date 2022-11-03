#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int n;
vector<pair<int, int> > g[100007];
bool root[100007];
int up[18][100007];
int tin[100007], tout[100007];
int h[100007];
int color[100007];
int sum[100007];

int tt = 0;
void dfs(int v, int pred, int hh, int ss, int cc){
	tin[v] = tt++;

	sum[v] = ss;
	h[v] = hh;
	color[v] = cc;

	up[0][v] = pred;
	for (int i = 1; i < 18; i++) up[i][v] = up[i - 1][up[i - 1][v]];

	for (auto to : g[v]) if (to.x != pred){
		dfs(to.x, v, hh + 1, ss + to.y, cc);
	}

	tout[v] = tt++;
}

bool isPred(int a, int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int getLca(int a, int b){
	if (isPred(a, b)) return a;
	if (isPred(b, a)) return b;
	for (int i = 17; i >= 0; i--) if (!isPred(up[i][a], b)) a = up[i][a];
	return up[0][a];
}

int getType(int a, int b){
	int len = h[b] - h[a];
	int ss = sum[b] - sum[a];
	if (ss == 0) return 1;
	if (len == ss) return 0;
	return -1;
}

int main(){ 
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if (a == -1){
			root[i] = 1;
			continue;
		}
		a--;
		g[a].pub(mp(i, b));
		g[i].pub(mp(a, b));
	}
	int sz = 0;
	for (int i = 0; i < n; i++) if (root[i]) dfs(i, i, 0, 0, sz), sz++;
	int m;
	cin >> m;
	while(m--){
		int type, a, b;
		cin >> type >> a >> b;
		a--; b--;
		int c = getLca(a, b);
		if (type == 1){
			if (b == c || a == b || color[a] != color[b]){
				cout << "NO\n";
				continue;
			}
			if (a == c && getType(a, b) == 1){
				cout << "YES\n";
				continue;
			} else cout << "NO\n";
		} else {
			if (b == c || a == b || color[a] != color[b]){
				cout << "NO\n";
				continue;
			}
			if (getType(c, b) == 0 && getType(c, a) == 1){
				cout << "YES\n";
				continue;
			} else cout << "NO\n";
		}
	}
}