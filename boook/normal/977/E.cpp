#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i , j , k)  for(int i = j ; i <  k ; ++i)
#define RREP(i , j , k) for(int i = j ; i >= k ; --i)
#define A  first
#define B  second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define MEM(i , j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i , j)     cout << i << " " << j << endl
#define DB4(i , j , k , l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 200900
#define INF 0x3f3f3f3f

int n , m , id[MAX] , use[MAX];
vector<int> v[MAX];
int DFS(int now , int idx){
	id[now] = idx;
	if(v[now].size() != 2) return 0; 
	int v1 = v[now][0] , v2 = v[now][1];
	if(idx == 1){
		int ans = DFS(v1 , idx + 1);
		if(id[v2] == 0) return 0;
		else return ans;
	}
	else {
		if(id[v2] == idx - 1) swap(v1 , v2);
		if(id[v1] != idx - 1) return 0;
		if(id[v2] == 1) return 1;
		else return DFS(v2 , idx + 1);
	}
}
void solve(int now){
	if(use[now]) return ;
	use[now] = 1;
	for(auto to : v[now]) solve(to);
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , m + 1){
    	int a , b;
    	cin >> a >> b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    int ans = 0;
    REP(i , 1 , n + 1) if(use[i] == 0){
    	ans += DFS(i , 1);
    	solve(i);
    }
    cout << ans << endl;
    return 0;
}