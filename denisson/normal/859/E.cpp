#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

const int mod = (int)1e9 + 7;

int n;
vector<int> g[400007];
bool was[400007];

int ww, mi;
void dfs(int v){
	ww++;
	if (v <= 2 * n) mi = min(mi, (int)g[v].size());
	was[v] = 1;
	for (int to : g[v]) if (!was[to]) dfs(to);
}

int main() { 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("cpr.in", "r", stdin);
    //freopen("cpr.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int cc = 2 * n + 1;
    for (int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	g[a].pub(cc + b);
    	g[cc + b].pub(a);
    	if (a != b) g[a].pub(cc + a), g[cc + a].pub(a);
    }
    int ans = 1;
    for (int i = 1; i <= 2 * n; i++) if (!was[i] && g[i].size()){
    	ww = 0, mi = 2;
    	dfs(i);
    	//cout << ww << ' ' << mi << endl;
    	if (ww % 2 == 1){
    		ans = ((ll)ans * (1 + ww / 2)) % mod;
    	} else {
    		if (mi != 1) ans = ans * 2 % mod;
    	}	
    }
    cout << ans;
}