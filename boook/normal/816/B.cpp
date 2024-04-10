/*input
2 1 1
1 1
200000 200000
90 100
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
#define MAX 300000
#define INF 0x3f3f3f3f

int n , m , k , x[MAX] , a[MAX][2] , b[MAX];
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) cin >> a[i][0] >> a[i][1];
	REP(i , 1 , n + 1) x[a[i][0]] ++ , x[a[i][1] + 1] --;
	REP(i , 1 , MAX) x[i] += x[i - 1];
	REP(i , 1 , MAX) b[i] = x[i] >= m;
	REP(i , 1 , MAX) b[i] += b[i - 1];
	REP(i , 1 , k + 1){
		int ql , qr;
		cin >> ql >> qr;
		cout << b[qr] - b[ql - 1] << endl;
	}
    return 0;
}