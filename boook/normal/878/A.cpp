/*input
3
| 3
^ 2
| 1
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

int n , in , x[100];
string s;

int32_t main(){
	cin >> n;
	REP(i , 1 , n + 1){
		cin >> s >> in;
		// DBGG("s = " , s);
		if(s == "|"){
			REP(j , 0 , 10){
				// DBGG("here" , "");
				if(in % 2 == 1) x[j] = 3;
				in >>= 1;
			}
		}
		else if(s == "&"){
			REP(j , 0 , 10){
				if(in % 2 == 0) x[j] = 2;
				in >>= 1;
			}
		}
		else if(s == "^"){
			REP(j , 0 , 10){
				if(in % 2 == 1){
					if(x[j] == 2) x[j] = 3;
					else if(x[j] == 3) x[j] = 2;
					else x[j] = 1 - x[j];
				}
				in >>= 1;
			}
		}
		// REP(j , 0 , 10) cout << x[j] << " " ; cout << endl;
	}
	int a = 0 , b = 0 , c = 0;
	REP(j , 0 , 10){
		if(x[j] == 1) a = a ^ (1 << j);
	}
	REP(j , 0 , 10){
		if(x[j] == 2);
		else b ^= (1 << j);
	}
	REP(j , 0 , 10){
		if(x[j] == 3){
			c ^= (1 << j);
		}
	}
	cout << 3 << endl;
	cout << "^ " << a << endl;
	cout << "& " << b << endl;
	cout << "| " << c << endl;
    return 0;
}