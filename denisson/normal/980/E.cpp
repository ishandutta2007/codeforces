#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
		   
using namespace std;
		   
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, k;
vector<int> g[1000007];

int p[1000007], was[1000007];

int up[20][1000007];

void dfs(int v, int pred){
	p[v] = pred;
	up[0][v] = pred;
	for (int i = 1; i < 20; i++) up[i][v] = up[i - 1][up[i - 1][v]];
	for (int to : g[v]) if (to != pred) dfs(to, v);
}

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(n - 1, n - 1);
	was[n - 1] = 1;

	int ost = n - k - 1;
	
	for (int i = n - 2; i >= 0; i--) if (!was[i]){	
		int len = 0;
		int v = i;
		for (int j = 19; j >= 0; j--) if (!was[up[j][v]]){
			len += (1 << j);
			v = up[j][v];
		}
		len++;
		//cout << i + 1 << ' ' << len << ' ' << ost << endl;
		if (len <= ost){
			ost -= len;
			int v = i;
			while(1){
				if (was[v]) break;
				was[v] = 1;
				v = p[v];
			}
		}
	}


	vector<int> t;
	for (int i = 0; i < n; i++) if (!was[i]) t.pb(i + 1);
	for (int x : t) cout << x << ' ';
}