/*input
1 0
2 3
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
#define MAX (1 << 19)
#define INF 0x3f3f3f3f

int n , m , x[MAX];
double sum = 0;
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , (1 << n)) cin >> x[i] , sum += x[i];
	printf("%.11f\n", sum / (1 << n));
	REP(i , 1 , m + 1){
		int a , b;
		cin >> a >> b;
		sum += -x[a] + b , x[a] = b;
		printf("%.11f\n", sum / (1 << n));
	}
    return 0;
}