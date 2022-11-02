/*input
6 6
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
#define MAX 300900
#define INF 0x3f3f3f3f

int n , m , d[MAX] , u[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	int sum = 0 , res = 0;
	REP(i , 1 , n + 1) for(int j = i + i ; j <= n ; j += i) d[j] ++;
	REP(i , 1 , n + 1) d[i] += d[i - 1];
	RREP(i , n , 1) if(d[i] >= m) res = i , sum = d[i];

	if(sum < m) return cout << "No" << endl , 0;
	cout << "Yes" << endl;
	set<PII> cc;
	REP(i , 1 , res + 1) u[i] = 1;
	REP(i , res / 2 + 1 , res + 1) cc.insert(mp(d[i] - d[i - 1] , i));

	sum -= m;
	while(sum){
		auto tmp = prev(cc.upper_bound(mp(sum , INF)));
		sum -= (*tmp).A , u[(*tmp).B] = 0;
		cc.erase(tmp);
	}
	int siz = 0;
	REP(i , 1 , res + 1) siz += u[i];
	cout << siz << endl;
	REP(i , 1 , res + 1) if(u[i]) cout << i << " "; cout << endl;
    return 0;
}