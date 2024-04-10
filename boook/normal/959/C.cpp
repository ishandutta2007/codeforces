/*input
8
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
#define MAX 
#define INF 0x3f3f3f3f


int32_t main(){
	IOS;
	int n;
	cin >> n;
	if(n <= 5) cout << -1 << endl;
	else {
		REP(i , 2 , 4 + 1) cout << "1 " << i << endl;
		REP(i , 5 , n + 1) cout << "2 " << i << endl;
	}
	REP(i , 2 , n + 1) cout << "1 " << i << endl;	
    return 0;
}