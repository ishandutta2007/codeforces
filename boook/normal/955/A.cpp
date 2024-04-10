/*input
17 41
1000 6 15 11
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int h , m , H , D , C , N;
int32_t main(){
	cin >> h >> m >> H >> D >> C >> N;
	int mm = h * 60 + m;
	double ans = (H / N + (H % N != 0)) * C;
	if(mm >= 20 * 60) ans *= 0.8;
	else if(mm <= 20 * 60){
		H += (20 * 60 - mm) * D;
		ans = min(ans , double((H / N + (H % N != 0)) * C) * 0.8);
	}
	printf("%.11f\n", ans);
    return 0;
}