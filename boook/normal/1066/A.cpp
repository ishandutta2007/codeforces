/*input
4
10 2 3 7
100 51 51 51
1234 1 100 199
1000000000 1 1 1000000000
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
#define MAX 
#define INF 0x3f3f3f3f

int n , a , b , c , d;
int32_t main(){
	IOS;
	cin >> n;
	REP(times , 1 , n + 1){
		cin >> a >> b >> c >> d;
		int all = a / b;
		int las = d / b - (c - 1) / b;
		cout << all - las << endl;
	}
    return 0;
}