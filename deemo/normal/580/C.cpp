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

const int max_n = 2e5;

int n, d, ans;
vector<int>	adj[max_n];
bool mark[max_n];
int f[max_n], s[max_n];

void get(int v, int p){
	if (v != 0){
		if (mark[v]){
			f[v] = max(s[p] + 1, f[p]);
			s[v] = s[p] + 1;
		}
		else{
			f[v] = f[p];
			s[v] = 0;
		}
	}	
	int cnt = 0;
	for (int i  = 0; i < adj[v].size(); i++){
		int u = adj[v][i];
		if (u == p)	continue;
		cnt++;
		get(u, v);
	}
	if (cnt == 0)
		if (f[v] <= d)	ans++;
}

int main(){
	read_fast;
	cin >> n >> d;
	for (int i = 0 ; i < n ; i++)
		cin >> mark[i];
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	f[0] = s[0] = mark[0];
	get(0, -1);
	cout << ans << endl;
    return 0;
}