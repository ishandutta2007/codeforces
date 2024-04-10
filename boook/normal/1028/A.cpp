/*input
5 6
WWBBBW
WWBBBW
WWBBBW
WWWWWW
WWWWWW
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

int n , m;
vector<int> _ , l;
int32_t main(){
	IOS;
	cin >> n >> m;
	string s;
	REP(i , 1 , n + 1){
		cin >> s , s = " " + s;
		REP(j , 1 , m + 1) if(s[j] == 'B') _.pb(i) , l.pb(j);
	}
	cout << (_[0] + _.back()) / 2 << " " << (l[0] + l.back()) / 2 << endl;
    return 0;
}