/*input
6
100 80 90 99
60 60 60 60
90 60 100 60
60 100 60 80
100 100 0 100
0 0 0 0
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
#define MAX 1010
#define INF 0x3f3f3f3f

int n;
PII v[MAX];
int32_t main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1){
		int a , b , c , d;
		cin >> a >> b >> c >> d;
		v[i] = mp(a + b + c + d , -i);
	}
	sort(v + 1 , v + 1 + n , greater<PII>());
	REP(i , 1 , n + 1) if(v[i].B == -1) return cout << i << endl , 0;
    return 0;
}