/*input
4
6 6 4 4
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
#define MAX 200900
#define INF 0x3f3f3f3f

int n , x[MAX];
map<int , int> cc;
int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	int allsum = 0;
	long double ans = 0;
	REP(i , 1 , n + 1){
		int tmp = allsum , cnt = i - 1;
		if(cc.find(x[i] - 1) != cc.end())
			cnt -= cc[x[i] - 1] , tmp -= cc[x[i] - 1] * (x[i] - 1);
		if(cc.find(x[i] + 0) != cc.end())
			cnt -= cc[x[i] + 0] , tmp -= cc[x[i] + 0] * (x[i] + 0);
		if(cc.find(x[i] + 1) != cc.end()) 
			cnt -= cc[x[i] + 1] , tmp -= cc[x[i] + 1] * (x[i] + 1);

		ans += cnt * x[i] - tmp;

		allsum += x[i] , cc[x[i]] ++;
	}
	
	printf("%.0Lf\n", ans);
    return 0;
}