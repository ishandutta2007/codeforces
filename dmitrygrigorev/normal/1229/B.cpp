#include <bits/stdc++.h>
#define int long long
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<vector<int> > data;

int binup[100000][18];
int G[100000][18];

vector<int> w;

int gcd(int x, int y){
	if (y==0) return x;
	return gcd(y, x%y);
}

void dfs(int vertex, int last){
	if (last != -1){
		binup[vertex][0] = last, G[vertex][0] = w[vertex];
		int lvl = 1, W = last;
		while (W != -1){
			if (G[W][lvl-1] == -1) break;
			G[vertex][lvl] = gcd(G[vertex][lvl-1], G[W][lvl-1]);
			binup[vertex][lvl] = binup[W][lvl-1];
			W = binup[W][lvl-1];
			lvl++;
		}
	}
	for (int i=0;i<data[vertex].size(); ++i){
		int to = data[vertex][i];
		if (to==last) continue;
		dfs(to, vertex);
	}
}

const int mod = 1000000007;

int mult(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod;
}

int add(int x, int y){
	if (x+y < 0) return x+y+mod;
	if (x+y>=mod) return x+y-mod;
	return x+y;
}

main(){
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i < n; ++i){
		int x;
		cin >> x;
		w.push_back(x);
	}

	data.assign(n, {});
	for (int i=0;i<n-1;++i){
		int u, v;
		cin >> u >> v;
		u--, v--;
		data[u].push_back(v);
		data[v].push_back(u);
	}

	for (int i=0;i<n;++i) for (int j=0;j<18;++j){
		binup[i][j] = -1;
		G[i][j] = -1;
	}
	dfs(0, -1);
	G[0][0] = w[0];
	int ans = 0;
	for (int i=0;i<n;++i){
		int start = i;
		int tut = w[start];
		while (start != -1){
			int jump = 0;
			for (int j=17; j >= 0; j--){
				if (start == -1) continue;
				if (G[start][j] == -1) continue;
				if (tut==0){
					if (G[start][j] == 0){
						start = binup[start][j];
						jump += (1<<j);
					}
					continue;
				}
				if (G[start][j] % tut == 0){
					start = binup[start][j];
					jump += (1<<j);
				}
			}
			int Q = (tut)%mod;
			ans = add(ans, mult(tut, jump));
			if (start==-1) break;
			tut = gcd(tut, w[start]);
		}
	}
	cout << ans;
	
}