/*input
100 100 8 100
3 5
7 94 12
100 1 47 0 42
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
#define MAX 100000
#define INF 0x3f3f3f3f

int c1 , c2 , c3 , c4;
int n , m , a[MAX] , b[MAX];
int32_t main(){
	IOS;
	cin >> c1 >> c2 >> c3 >> c4;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> a[i];
	REP(i , 1 , m + 1) cin >> b[i];
	int v1 = 0 , v2 = 0;
	REP(i , 1 , n + 1){
		v1 += min(a[i] * c1 , c2);
	}
	v1 = min(v1 , c3);
	REP(i , 1 , m + 1){
		v2 += min(b[i] * c1 , c2);
	}
	v2 = min(v2 , c3);
	cout << min(v1 + v2 , c4) << endl;
    return 0;
}