/*input
4
2 4 1 3
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
#define int long long
#define MAX 5050
#define INF 0x3f3f3f3f

int n , x[MAX] , cnt[MAX] , win[MAX];
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n);
	REP(i , 1 , n + 1) REP(j , 1 , i){
		cnt[x[i] - x[j]] ++;
	}
	double ans = 0 , tmp = n * (n - 1) / 2;;
	REP(i , 1 , MAX) REP(j , 1 , MAX){
		if(i + j < MAX) win[i + j] += cnt[i] * cnt[j];
	}
	REP(i , 1 , MAX) win[i] += win[i - 1];
	REP(i , 1 , MAX){
		ans += cnt[i] * win[i - 1];
	}
	printf("%.11f\n", (double)ans / tmp / tmp / tmp);
    return 0;
}