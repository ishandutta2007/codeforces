/*input
6
4 7 12 100 150 199
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

int n , x[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int ans = 1 , now = 2 , val = 1;
	while(now <= n){
		if(x[now - 1] + x[now - 1] >= x[now]) val ++ , now ++;
		else now ++ , val = 1;
		ans = max(ans , val);
		// DBGG(now - 1 , val);
	}
	cout << ans << endl;
    return 0;
}