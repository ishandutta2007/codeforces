/*input
6
2 1 0 2 1 2
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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , x[MAX] , c[MAX];
int main(){
	IOS;
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) c[x[i]] ++;
	int base , big = 0;
	REP(i , 1 , n + 1) big = max(big , x[i]);
	if(c[0] != 1) return cout << -1 << endl , 0;
	REP(i , 1 , n + 1){
		if(c[i] > i * 4) return cout << -1 << endl , 0; 
		if(c[i] != i * 4){ base = i - 1; break; }
	}
	// REP(i , 1 , big + 1) cout << c[i] << " " ; cout << endl;
	REP(i , 1 , n + 1){
		if(n % i == 0){
			vector<vector<int> > v(i + 1 , vector<int>(n / i + 1));
			vector<int> sol(big + 1 , 0);
			int v1 = i - 1 - base , v2 = big - v1 , ok = 1;
				// DB4(i , n / i , v1 , v2);
			if(0 <= v1 && v1 < i && 0 <= v2 && v2 < n / i){
				REP(ii , 0 , i) REP(jj , 0 , n / i){
					int val = abs(ii - v1) + abs(jj - v2);	
					if(val > big) ok = 0;
					else sol[val] ++;
				}

				REP(ii , 1 , big + 1) if(sol[ii] != c[ii]) ok = 0;
				if(ok == 1){
					cout << i << " " << n / i << endl;
					cout << v1 + 1 << " " << v2 + 1 << endl;
					return 0;
				}
			}
			vector<vector<int> > ().swap(v);
			vector<int> ().swap(sol);
		}
	}
	cout << -1 << endl;
    return 0;
}