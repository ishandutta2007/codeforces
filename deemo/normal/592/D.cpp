//quote needed

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;
#define to_string(x) ({ string _str; stringstream _ss; _ss << x;  _ss >> _str; _str; })
#define to_int(x) ({ int _x; stringstream _ss; _ss << x; _ss >> _x; _x; })

const int max_n = 1e6;

int n, m, cnt, ans;
vector<int>	adj[max_n];
bool del[max_n];
int save[max_n], save2[max_n];
int depth[max_n], depth2[max_n];
bool mark[max_n];

bool f(int v, int p){
	bool ret = 0;
	if (mark[v])	ret = 1;
	for (int u:adj[v]){
		if (u == p)	continue;
		ret |= f(u, v);
	}
	if (ret == 0)	del[v] = 1, cnt--;
	return	ret;
}

void dfs(int v, int p, int d){
	depth[v] = d;
	for (int u:adj[v]){
		if (u == p)	continue;
		if (del[u])	continue;
		dfs(u, v, d + 1);
	}
}

void dfs2(int v, int p, int d){
	depth2[v] = d;
	for (int u:adj[v]){
		if (u == p)	continue;
		if (del[u])	continue;
		dfs2(u, v, d + 1);
	}
}

void fin(){
	int u;
	for (int i = 0; i < n; i++)
		if (del[i] == 0)	u = i;
	dfs(u, -1, 0);
	int maxi = 0;
	for (int i = 0; i < n; i++)
		if (del[i] == 0 && depth[i] >= maxi){
			maxi = depth[i];
			u = i;
		}
	dfs(u, -1, 0);
	int v;
	maxi = 0;
	for (int i = 0; i < n; i++){
		if (del[i] == 0 && depth[i] >= maxi){
			maxi = depth[i];
			v = i;
		}
	}
	dfs2(v, -1, 0);

	int sum = 2 * (cnt - 1);
	ans = -1, maxi = 1e9;
	for (int i = 0; i < n; i++){
		if (del[i] == 0){
			int t = 2 * cnt - 2 - depth[i];
			t = min(t, 2 * cnt - 2 - depth2[i]);
			if (t < maxi){
				maxi = t;
				ans = i + 1;
			}
		}
	}
	cout << ans << endl;
	cout << maxi << endl;
}

int main(){
	read_fast;
	cin >> n >> m;
	cnt = n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a-- , b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int z;
	for (int i = 0; i < m; i++){
		int a;	cin >> a;	a--;
		mark[a] = 1;
		z = a;
	}
	f(z, -1);
	fin();
    return 0;
}