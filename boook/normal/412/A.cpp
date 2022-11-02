/*input
2 2
R1
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

int n , m;
string s;
int32_t main(){
	cin >> n >> m >> s;
	int v1 = m - 1 , v2 = n - m;
	if(v1 < v2){
		REP(i , 0 , v1) cout << "LEFT" << endl;
		REP(i , 0 , s.size()){
			if(i != 0) cout << "RIGHT" << endl;
			cout << "PRINT " << s[i] << endl;
		}
	}
	else { 
		REP(i , 0 , v2) cout << "RIGHT" << endl;
		RREP(i , s.size() - 1 , 0){
			cout << "PRINT " << s[i] << endl;
			if(i != 0) cout << "LEFT" << endl;
		}
	}
    return 0;
}