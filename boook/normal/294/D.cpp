/*input
3 3
1 2 DL
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
#define int long long
#define INF 0x3f3f3f3f

int n , m , x , y , dir;
int X[] = {1 , -1 , -1 , 1};
int Y[] = {-1 , -1 , 1 , 1};
string s;
map<PII , int> cc;
int IN(int a , int b){ return 1 <= a && a <= n && 1 <= b && b <= m; }
int32_t main(){
	IOS;
	cin >> n >> m >> x >> y >> s;
	if(s == "DL") dir = 0;
	if(s == "UL") dir = 1;
	if(s == "UR") dir = 2;
	if(s == "DR") dir = 3;
	int ans = 1 , step;
	cc[mp(x , y)] ++;
	while(cc.size() != n + m - 2){
		step = 0;
		RREP(i , 19 , 0){
			int tox = x + X[dir] * (1 << i) , toy = y + Y[dir] * (1 << i);
			if(IN(tox , toy)) x = tox , y = toy , step += (1 << i);
		}
		cc[mp(x , y)] ++ , ans += step;
		if(cc[mp(x , y)] == 4) return cout << -1 << endl , 0;
		if((x == 1 || x == n) && (y == 1 || y == m)){
			if(x == 1 && y == 1) dir = 3;
			if(x == 1 && y == m) dir = 0;
			if(x == n && y == 1) dir = 2;
			if(x == n && y == m) dir = 1;
		}
		else if(x == 1) dir = (dir * 3 + 1) % 4; // 1 , 2
		else if(y == 1) dir = (dir * 3 + 3) % 4; // 0 , 1
		else if(x == n) dir = (dir * 3 + 1) % 4; // 0 , 3
		else if(y == m) dir = (dir * 3 + 3) % 4; // 2 , 3
		// cout << "dir = " << ans << " ";DB4("x = " , x , "y = " , y);
	}
	cout << ans << endl;

    return 0;
}