
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int maxn = 3*100*1000 + 5;

int t[maxn], x[maxn], y[maxn], par[maxn];
vector <int> v[maxn];
bool mark[maxn];

int dfs(int cur){
	int res = 1;
	mark[cur] = true;
	for (int u : v[cur])
		if (!mark[u]){
			par[u] = cur;
			res += dfs(u);
		}
	return res;
}

int main(){
	int n = in(), m = in(), s = in()-1;
	for (int i = 0; i < m; i++){
		t[i] = in()-1;
		x[i] = in()-1;
		y[i] = in()-1;
		if (t[i] == 0)
			v[x[i]].pb(y[i]);
	}
	stringstream out;
	out << dfs(s) << '\n';
	for (int i = 0; i < m; i++){
		if (t[i]){
			if (mark[x[i]])
				out << '-';
			else
				out << '+';
			v[x[i]].pb(y[i]);
			v[y[i]].pb(x[i]);
		}
	}
	out << '\n';
	fill(mark, mark + n, false);
	fill(par, par + n, -1);
	cout << dfs(s) << '\n';
	for (int i = 0; i < m; i++){
		if (t[i]){
			if (x[i] == par[y[i]])
				cout << '+';
			else
				cout << '-';
		}
	}
	cout << '\n';
	cout << out.str();
	return 0;
}