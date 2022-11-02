/*input
1500 1000 176 177
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

int a , b , c , d;
int32_t main(){
	IOS;
	cin >> a >> b >> c >> d;
	int v1 = max(a * 3 / 10 , a - a / 250 * c);
	int v2 = max(b * 3 / 10 , b - b / 250 * d);
	if(v1 == v2) return cout << "Tie" << endl , 0;
	else if(v1 > v2) return cout << "Misha" << endl , 0;
	else if(v1 < v2) return cout << "Vasya" << endl , 0;
    return 0;
}