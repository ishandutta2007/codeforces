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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200500
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , cnt , dot , x[MAX] , two[MAX];
int use[MAX] , low[MAX] , dep[MAX];
vector<int> v[MAX];
void DFS(int now , int fa , int deep){
	use[now] = 1 , dot ++;
	low[now] = deep;
	dep[now] = deep;
	for(auto to : v[now]) if(to != fa){
		if(use[to] == 1){
			low[now] = min(low[now] , dep[to]);
		}
		else {
			DFS(to , now , deep + 1);
			if(low[to] > dep[now]) cnt ++;
			low[now] = min(low[now] , low[to]);
		}
	}
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) v[i].pb(x[i]) , v[x[i]].pb(i);
    int ans = 1;
    two[0] = 1;
    REP(i , 1 , n + 1) two[i] = two[i - 1] * 2 % mod;
    REP(i , 1 , n + 1){
    	if(use[i] == 0){
    		cnt = 0 , dot = 0;
    		DFS(i , i , 0);
    		// DB4("cnt = " , cnt , "dot = " , dot);
    		cnt = dot - cnt , cnt = max(cnt , 2LL);
    		ans = ans * two[dot - cnt] % mod;
    		ans = ans * (two[cnt] - 2) % mod;
    	}
    }
    cout << ans << endl;
    return 0;
}