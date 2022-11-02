/*input
5 2 1 5
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

int n , now , l , r;
int32_t main(){
	cin >> n >> now >> l >> r;
	if(l == 1 && r == n) cout << 0 << endl;
	else if(l == 1){
		cout << abs(r - now) + 1 << endl;
	}
	else if(r == n){
		cout << abs(now - l) + 1 << endl;
	}
	else {
		int aa = abs(now - l) + 1 + abs(l - r) + 1;
		int bb = abs(now - r) + 1 + abs(r - l) + 1;
		cout << min(aa , bb) << endl;
	}
    return 0;
}