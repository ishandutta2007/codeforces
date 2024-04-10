/*input
3 1
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

int n , m;
int32_t main(){
	IOS;
	cin >> n >> m;
	int sml = INF , big = -1;
	REP(i , 0 , n + 1){
		int las = n - i;
		if((las + 1) / 2 <= m && m <= las * (las - 1) / 2){
			sml = min(sml , i);
			big = max(big , i);
		}
	}
	cout << sml << " " << big << endl;
    return 0;
}