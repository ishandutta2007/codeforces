/*input
3 10
10 20 30
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100000
#define INF 0x3f3f3f3f

int n , k , x[MAX];
int32_t main(){
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	int fr = 0 , now = 0 , ba = 0;
	REP(i , 1 , n + 1){
		if(x[i] <  k) fr ++;
		if(x[i] == k) now ++;
		if(x[i] >  k) ba ++;
	}
	int ans = 0;
	if(now == 0) now ++ , ans ++;
	// DB4(fr , now , ba , ans);
	REP(i , 0 , INF){
		int sum = fr + now + ba + i;
		int kk = (sum + 1) / 2 - fr;
		if(fr < ba) kk -= i;
		// DB4("" , i , kk , sum);
		if(1 <= kk && kk <= now){
			cout << i + ans << endl;
			return 0;
		}
	}
    return 0;
}