/*input
4 2 3
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
#define MAX 
#define INF 0x3f3f3f3f

void Y(){
	cout << "YES" << endl;
	exit(0);
}
void N(){
	cout << "NO" << endl;
	exit(0);	
}
int x[3];
int32_t main(){
	REP(i , 0 , 3) cin >> x[i];
	sort(x , x + 3);
	
	if(x[0] == 1) Y();
	if(x[0] == 2 && x[1] == 2) Y();
	if(x[0] == 3 && x[1] == 3 && x[2] == 3) Y();
	if(x[0] == 2 && x[1] == 4 && x[2] == 4) Y();
	N();
    return 0;
}