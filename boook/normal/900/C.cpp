/*input
5
3 1 5 2 4
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
#define MAX 100900
#define INF 0x3f3f3f3f

int bit[MAX] , n , x[MAX];
int cnt[MAX];
int update(int from , int val){
	for(int i = from ; i < MAX ; i += i & -i)
		bit[i] += val;
}
int query(int from){
	int cnt = 0;
	for(int i = from ; i > 0 ; i -= i & -i)
		cnt += bit[i];
	return cnt;
}
int vv[MAX];
int32_t main(){
	IOS , cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int big = 0 , all = 0;
	REP(i , 1 , n + 1){
		int tmp = query(n + 1) - query(x[i]);
		if(tmp == 1) cnt[big] ++;
		if(tmp == 0) vv[x[i]] = 1 , all ++;

		update(x[i] , 1);
		big = max(big , x[i]);
	}
	int good = 0 , ans = x[1];
	REP(i , 1 , n + 1){
		good = max(good , cnt[i] + all - vv[i]);
	}
	RREP(i , n , 1){
		if(cnt[i] + all - vv[i] == good) ans = i;
	}
	cout << ans << endl;
    return 0;
}