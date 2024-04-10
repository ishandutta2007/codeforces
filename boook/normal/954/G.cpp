/*input
5 1 1
2 1 2 1 2
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
#define int int_fast64_t
#define MAX 2000900
#define INF 0x3f3f3f3f

int n , r , k , x[MAX] , p[MAX];
int add[MAX];
int judge(int now){
	REP(i , 1 , n + 1) add[i] = 0;
	int cost = 0 , pre = 0;
	REP(i , 1 , n + 1){
		pre += add[i];
		int val = p[i + r] + pre;
		if(i - r - 1 >= 0) val -= p[i - r - 1];

		if(val < now){
			int tmp = now - val;
			cost += tmp;
			if(cost > k) return 0;
			add[i] += tmp , pre += tmp;
			add[i + r + r + 1] -= tmp;
		}
	}
	return cost <= k;
}
int32_t main(){
	IOS;
	cin >> n >> r >> k;
	
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + n + 1) p[i] = p[i - 1] + x[i];

 	int ans = 0;
	RREP(i , 61 , 0){
		int to = ans + (1LL << i);
		if(judge(to)) ans = to;
	}
	cout << ans << endl;
    return 0;
}