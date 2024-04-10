/*input
5 3
...
.S.
###
.E.
...
3
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
#define MAX 500
#define INF 0x3f3f3f3f

int n , m , d[] = {0 , 1 , 2 , 3};
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
string s[MAX] , goal;
PII ss;

int32_t main(){
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] == 'S') ss = mp(i , j);
	cin >> goal;
	int ans = 0;
	do{
		int ok = 1;
		PII now = ss;
		for(auto to : goal){
			int dir = d[to - '0'];
			int tox = now.A + X[dir];
			int toy = now.B + Y[dir];
			if(tox >= 0 && tox < n && toy >= 0 && toy < m){
				now = mp(tox , toy);
				if(s[now.A][now.B] == 'E') break;
				if(s[now.A][now.B] == '#'){
					ok = 0;
					break;
				}
			}
			else {
				ok = 0;
				break;
			}
		}
		if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m){
			if(s[now.A][now.B] != 'E') ok = 0;
		}
		else ok = 0;
		ans += ok;
	}while(next_permutation(d , d + 4));
	cout << ans << endl;
    return 0;
}