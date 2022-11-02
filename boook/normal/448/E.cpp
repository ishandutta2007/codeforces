/*input
4 2
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
#define int long long
#define INF 0x3f3f3f3f
#define MAX 200000
#define N 100000

int n , k;
vector<int> ans , sol , v[MAX];

void Print(){
	for(auto to : ans) cout << to << " "; cout << endl;	
	exit(0);
}
void DFS(int now , int floor){
	if(ans.size() == N) Print();
	if(floor == k || now == 0) ans.pb(sol[now]);
	else for(auto to : v[now]) DFS(to , floor + 1);
}
int32_t main(){
	IOS;
	cin >> n >> k , k = min(k , N + 1LL);
	REP(i , 1 , n + 1){
		if(i * i > n) break;
		else if(i * i == n) sol.pb(i);
		else if(n % i == 0) sol.pb(i) , sol.pb(n / i);
	}
	sort(ALL(sol));
	REP(i , 0 , sol.size()){
		REP(j , 0 , i + 1) if(sol[i] % sol[j] == 0) v[i].pb(j);
	}
	DFS(sol.size() - 1 , 0) , Print();
    return 0;
}