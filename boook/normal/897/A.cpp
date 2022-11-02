/*input
5 3
wxhak
3 3 h x
1 5 x a
1 3 w g
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
#define MAX 190
#define INF 0x3f3f3f3f

int n , m;
string s;
int32_t main(){
	IOS;
	cin >> n >> m >> s;
	REP(i , 1 , m + 1){
		int l , r;
		char a , b;
		cin >> l >> r >> a >> b , l -- , r --;
		REP(j , l , r + 1) if(s[j] == a) s[j] = b;
	}
	cout << s << endl;
    return 0;
}