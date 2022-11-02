/*input
3
1 1000 10000
10 100 100000
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
#define MAX 400000
#define INF 0x3f3f3f3f

int n , x[MAX][2] , pre[MAX][2] , suf[MAX][2] , ss[MAX][2];
int solve(){
	REP(j , 0 , 2){
		REP(i , 1 , n + 1) pre[i][j] = x[i][j] * i;
		REP(i , 1 , n + 1) suf[i][j] = x[i][j] * -i;
		REP(i , 1 , n + 1)  ss[i][j] = x[i][j];

		REP(i , 1 , n + 1) pre[i][j] += pre[i - 1][j];
		REP(i , 1 , n + 1) suf[i][j] += suf[i - 1][j];
		REP(i , 1 , n + 1)  ss[i][j] +=  ss[i - 1][j];
	}
	int pos = 0 , now = 0 , ans = 0 , tmp;
	REP(i , 1 , n + 1){
		if(i % 2 == 1){
			tmp = 0;
			tmp += (pre[n][0] - pre[i - 1][0]) - (ss[n][0] - ss[i - 1][0]) * (i - pos);
			tmp += (suf[n][1] - suf[i - 1][1]) + (ss[n][1] - ss[i - 1][1]) * (n + n - (-i) - 1);
			// cout << tmp + now << endl;
			ans = max(ans , tmp + now);

			now = now + x[i][0] * pos , pos ++;
			now = now + x[i][1] * pos , pos ++;
		}
		if(i % 2 == 0){
			tmp = 0;
			tmp += (pre[n][1] - pre[i - 1][1]) - (ss[n][1] - ss[i - 1][1]) * (i - pos);
			tmp += (suf[n][0] - suf[i - 1][0]) + (ss[n][0] - ss[i - 1][0]) * (n + n - (-i) - 1);
			// cout << now << endl;
			// cout << tmp << endl;
			// cout << tmp + now << endl;
			ans = max(ans , tmp + now);

			now = now + x[i][1] * pos , pos ++;
			now = now + x[i][0] * pos , pos ++;
		}
	}
	return ans;
}
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i][0];
	REP(i , 1 , n + 1) cin >> x[i][1];
	cout << solve() << endl;
    return 0;
}



// tmp = 0;
			// tmp += (suf[n][1] - suf[i][1]) + (ss[n][1] - ss[i][1]) * (i + 1 - pos);
			// cout << tmp << endl;
			// exit(0);
			// tmp += (pre[n][0] - pre[i][0]) - (ss[n][0] - ss[i][0]) * (n + n - (-(i + 1)));
			// ans = max(ans , tmp + now);