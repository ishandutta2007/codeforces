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

const int max_n = 5e3;

int n;
ll sum1, sum2;
vector<pair<int, int>>	adj[max_n];
bool mark[max_n];

void dfs(int v, int p){
	mark[v] = 1;
	for (pair<int, int>	u:adj[v]){
		if (u.first == p)	continue;
		if (u.second < 0)	sum2 += -u.second;
		if (!mark[u.first])
			dfs(u.first, v);
		break;
	}
}

int main(){
	read_fast;
	cin >> n;
	for (int i = 0; i < n; i++){
		int a, b, c;	cin >>a >> b >> c;
		a--, b--;
		adj[a].pb({b, c});
		adj[b].pb({a, -c});
		sum1 += c;
	}
	dfs(0, -1);
	cout << min(sum1 - sum2, sum2) << endl;
    return 0;
}