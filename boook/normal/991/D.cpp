/*input
0XXX0
00000

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
#define MAX 1000
#define INF 0x3f3f3f3f

string a , b;
int x[MAX];
int32_t main(){
	IOS;
	cin >> a >> b;
	REP(i , 0 , a.size()){
		if(a[i] != '0' && b[i] != '0') x[i] = 0;
		if(a[i] != '0' && b[i] == '0') x[i] = 1;
		if(a[i] == '0' && b[i] != '0') x[i] = 2;
		if(a[i] == '0' && b[i] == '0') x[i] = 3;
	}
	int ans = 0 , res = -1;
	REP(i , 0 , a.size()){
		if(x[i] == 0){
			res = -1;
		}
		else if(x[i] == 1){
			if(res == 3) ans ++ , res = -1;
			else res = 1;
		}
		else if(x[i] == 2){
			if(res == 3) ans ++ , res = -1;
			else res = 2;
		}
		else if(x[i] == 3){
			if(res == 1 || res == 2 || res == 4) ans ++ , res = -1; 
			else if(res == 3) ans ++ , res = 4;
			else res = 3;
		}
		// DBGG(ans , res);
	}
	cout << ans << endl;
    return 0;
}