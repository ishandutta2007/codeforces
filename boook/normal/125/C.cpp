/*input
50
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
#define MAX 100000
#define INF 0x3f3f3f3f


int n;
vector<int> v[MAX];
int32_t main(){
	cin >> n;
	REP(ii , 1 , n + 1){
		int all = (ii * (ii + 1) / 2);
		if(n < all){
			cout << ii << endl;
			int po = 1;
			REP(i , 1 , ii + 1){
				REP(j , i + 1 , ii + 1){
					v[i].pb(po);
					v[j].pb(po);
					po ++;
				}
			}
			REP(i , 1 , ii + 1){
				for(auto to : v[i]) cout << to << " " ;
				cout << endl;
			}
			return 0;
		}
	}
    return 0;
}