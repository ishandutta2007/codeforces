/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

vector<pair<int,pii>> v;
map<int,int> cval;

int grid[102][102], parent[102], tot;
int n, k, max_flow = 0;  
map<int,int> pr;

bool prime(int x) {
	for (int i = 2;;++i) {
		if (i*i > x) break;
		if (x % i == 0) return 0;
	}
	return 1;
}
 
bool bfs() {
    bool visited[102];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
 
    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<102; v++) {
            if (visited[v] == false && grid[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    return visited[101];
}
 
void fordFulkerson() {
    int u,v;
    while (bfs()) {
        int path_flow = INT_MAX;
        for (v = 101; v != 0; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, grid[u][v]);
        }
 
        for (v = 101; v != 0; v = parent[v]) {
            u = parent[v];
            grid[u][v] -= path_flow;
            grid[v][u] += path_flow;
        }
 
        max_flow += path_flow;
    }
}
 
void input() {
	cin >> n >> k;
	F0R(i,n) {
		int p,c,l; cin >> p >> c >> l;
		v.pb({l,{p,c}});
		cval[c] = 0;
	}
	sort(v.begin(),v.end());
}

void add(pii a) {
	if (a.s == 1) {
		int sum = grid[cval[a.s]][0]+grid[0][cval[a.s]];
		if (sum < a.f) {
			grid[0][cval[a.s]] += a.f-sum;
			tot += a.f-sum;
		}
	} else if (a.s % 2 == 0) {
		grid[cval[a.s]][101] += a.f;
		tot += a.f;
	} else if (a.s % 2 == 1) {
		grid[0][cval[a.s]] += a.f;
		tot += a.f;
	}
}

int main() {
	input();
	int num = 1;
	for (auto a: cval) cval[a.f] = num++;
	for (auto a: cval) if (a.f % 2 == 1) 
		for (auto b: cval) if(b.f % 2 == 0)
			if(prime(a.f+b.f))
				grid[a.s][b.s] = MOD;
				
	for (auto a: v) {
		add(a.s);
		fordFulkerson();
		if (tot-max_flow >= k) {
			cout << a.f;
			return 0;
		}
	}
	cout << -1;
}