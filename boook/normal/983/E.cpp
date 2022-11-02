/*input
7
1 1 2 3 4 1
4
4 7
3 5
7 6
7 6
6
4 6
3 1
3 2
2 7
6 3
5 3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200090
#define INF 0x3f3f3f3f
#define LOGN 20

int n , m , k , p[MAX];
vector<int> v[MAX];

int in[MAX] , out[MAX] , pos = 0 , dep[MAX];
int sp[MAX][LOGN] , jump[MAX][LOGN];

void DFS0(int now , int fa , int deep){
     in[now] = ++pos;
    dep[now] = deep;
    sp[now][0] = fa;
    for(auto to : v[now]) DFS0(to , now , deep + 1);
    out[now] = ++pos;
}
int FA(int fa , int now){
    return (in[fa] <= in[now] && out[now] <= out[fa]);
}
int LCA(int a , int b){
    if(FA(a , b)) return a;
    RREP(i , LOGN - 1 , 0) if(FA(sp[a][i] , b) == 0) a = sp[a][i];
    return sp[a][0];
}
void solveinitLca(){
    DFS0(1 , 0 , 0) , out[0] = ++pos;
    REP(j , 1 , 20) REP(i , 1 , n + 1) sp[i][j] = sp[sp[i][j - 1]][j - 1];
}
PII query(int from , int to){
    if(from == to) return mp(0 , from);
    if(dep[jump[from][0]] <= dep[to]) return mp(1 , from);
    if(dep[jump[from][LOGN - 1]] > dep[to]) return mp(-1 , -1);
    int cnt = 0;
    RREP(i , LOGN - 1 , 0){
        int val = jump[from][i];
        if(dep[val] > dep[to]) from = val , cnt += (1 << i);
    }
    return mp(cnt + 1 , from);
}
int DFS_init_jump(int now){
    int ans = jump[now][0];
    for(auto to : v[now]){
        int tmp = DFS_init_jump(to);
        if(dep[tmp] < dep[ans]) ans = tmp;
    }
    return jump[now][0] = ans;
}
int ans[MAX];
set<int> bus[MAX];
vector<PII> q[MAX];
void DFS_solve(int now){
	for(auto to : v[now]){
		DFS_solve(to);
		if(bus[to].size() > bus[now].size()) swap(bus[to] , bus[now]);
		for(auto val : bus[to]) bus[now].insert(val);
	}
	for(auto to : q[now]){
		auto tmp = bus[now].lower_bound(in[to.A]);
		if(tmp != bus[now].end() && (*tmp) <= out[to.A]) ans[to.B] --;
	}
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 2 , n + 1) cin >> p[i] , v[p[i]].pb(i);

    solveinitLca();
    REP(i , 1 , n + 1) jump[i][0] = i;
    cin >> m;
    REP(i , 1 , m + 1){
        int v1 , v2;
        cin >> v1 >> v2;
        int lca = LCA(v1 , v2);
        bus[v1].insert(in[v2]);
        bus[v2].insert(in[v1]);
        if(dep[lca] < dep[jump[v1][0]]) jump[v1][0] = lca;
        if(dep[lca] < dep[jump[v2][0]]) jump[v2][0] = lca;
    }

    DFS_init_jump(1);
    REP(j , 1 , 20) REP(i , 1 , n + 1) jump[i][j] = jump[jump[i][j - 1]][j - 1];

    cin >> k;
    REP(i , 1 , k + 1){
        int v1 , v2;
        cin >> v1 >> v2;
        int lca = LCA(v1 , v2);

        if(v1 != lca && v2 != lca){

            PII low1 = query(v1 , lca);
            PII low2 = query(v2 , lca);

            if(low1.A == -1 || low2.A == -1) ans[i] = -1;
            else {
            	ans[i] = low1.A + low2.A;
            	// DB4("here = " , low1.A , low2.A , "");
            	// DB4("here = " , low1.B , low2.B , "");
            	q[low1.B].pb(low2.B , i);
            }
        }
        else if(v1 == lca){
            PII low2 = query(v2 , lca);
            if(low2.A == -1) ans[i] = -1;
            else ans[i] = low2.A;
        }
        else if(v2 == lca){
            PII low1 = query(v1 , lca);
            if(low1.A == -1) ans[i] = -1;
            else ans[i] = low1.A;
        }
    }
    DFS_solve(1);
    REP(i , 1 , k + 1) cout << ans[i] << endl;
    return 0;
}