#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
typedef long long ll;

int n, m;
int a[500][500];
int r1, c1, r2, c2;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vii v[250000];
bool dfs_num[250000];
vector<vii> AdjList;
bool result;

void dfs(int k){
	dfs_num[k] = 1;
	if ((abs(k / m - r2) + abs(k % m - c2) == 1) && a[r2][c2] == 0) {cout<<"YES"; result = true; return;}
	FOR(i, AdjList[k].size()) {if (result) return; int l = AdjList[k][i].first; if (dfs_num[l] == 0) {if (l == r2 * m + c2) {if (a[r2][c2] == 0 || AdjList[l].size() > 1){cout<<"YES"; result = true; return;} return;} dfs(l);}}
}

void solve(){
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	memset(a, 0, sizeof(a));
	memset(dfs_num, 0, sizeof(dfs_num));
	cin>>n>>m;
	FOR(i, n) {char str[501]; cin>>str; FOR(j, m) {if (str[j] == '.') a[i][j] = 1;}}
	cin>>r1>>c1>>r2>>c2;
	r1--; c1--; r2--; c2--;
	a[r1][c1] = 1;
	FOR(i, n) {FOR(j, m) {if (a[i][j] == 1) {
				if (i > 0 && a[i - 1][j] == 1) {v[i * m + j].push_back(ii((i - 1) * m + j, 1)); v[(i - 1) * m + j].push_back(ii(i * m + j, 1));}
				if (j > 0 && a[i][j - 1] == 1) {v[i * m + j].push_back(ii(i * m + j - 1, 1)); v[i * m + j - 1].push_back(ii(i * m + j, 1));}
			}
		}
	}
	FOR(i, n * m) AdjList.push_back(v[i]);
	a[r1][c1] = 0;
	result = false;
	dfs(r1 * m + c1);
	if (!result) cout<<"NO";
}

int main(){
	solve();
	return 0;
}