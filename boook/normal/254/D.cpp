/*input
4 4 1
XXXX
XR.X
X.RX
XXXX
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
// #define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , k , all , dis[MAX][MAX] , res[MAX][MAX];
int X[] = {-1 , 0 , 0 , 1} , Y[] = {0 , -1 , 1 , 0};
string s[MAX];
void solve(PII from){
	queue<PII> qu;
	MEM(dis , INF) , dis[from.A][from.B] = 0 , qu.push(from);
	while(qu.size()){
		PII now = qu.front(); qu.pop();
		if(dis[now.A][now.B] > k) continue;
		REP(i , 0 , 4){
			int x = now.A + X[i] , y = now.B + Y[i];
			if(s[x][y] != 'X' && dis[x][y] > dis[now.A][now.B] + 1){
				dis[x][y] = dis[now.A][now.B] + 1;
				qu.push(mp(x , y));
			}
		}
	}
	vector<PII> las , det;
	REP(i , 0 , n) REP(j , 0 , m){
		if(dis[i][j] > k && s[i][j] == 'R') las.pb(mp(i , j));
	}
	if(las.size() == 0){
		REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] != 'X' && from.A != i && from.B != j){
			cout << i + 1 << " " << j + 1 << " ";
			cout << from.A + 1 << " " << from.B + 1 << endl;
			exit(0);
		}
	}
	else if(las.size() > 280) return ;
	else {
		MEM(res , 0) , MEM(dis , INF);
		for(auto to : las){
			det.clear();
			qu.push(to) , dis[to.A][to.B] = 0;

			while(qu.size()){
				PII now = qu.front(); qu.pop();
				det.pb(now);
				if(dis[now.A][now.B] > k) continue;
				else res[now.A][now.B] ++;

				if(res[now.A][now.B] == las.size()){
					cout << from.A + 1 << " " << from.B + 1 << " " ;
					cout << now.A + 1 << " " << now.B + 1 << endl;
					exit(0);
				}
				REP(i , 0 , 4){
					int x = now.A + X[i] , y = now.B + Y[i];
					if(s[x][y] != 'X' && dis[x][y] > dis[now.A][now.B] + 1){
						dis[x][y] = dis[now.A][now.B] + 1;
						qu.push(mp(x , y));
					}
				}
			}
			for(auto ii : det) dis[ii.A][ii.B] = INF;
		}
	}
}
int32_t main(){
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	IOS;
	cin >> n >> m >> k;
	REP(i , 0 , n) cin >> s[i];

	PII tmp;
	REP(i , 0 , n) REP(j , 0 , m) if(s[i][j] == 'R') tmp = mp(i , j) , all ++;
	queue<PII> qu;
	MEM(dis , INF) , dis[tmp.A][tmp.B] = 0 , qu.push(tmp);
	vector<PII> sol;
	while(qu.size()){
		int x = qu.front().A , y = qu.front().B; qu.pop();
		if(dis[x][y] > k) continue;
		else sol.pb(mp(x , y));
		REP(i , 0 , 4){
			int xx = x + X[i] , yy = y + Y[i];
			if(s[xx][yy] != 'X' && dis[xx][yy] > dis[x][y] + 1){
				dis[xx][yy] = dis[x][y] + 1;
				qu.push(mp(xx , yy));
			}
		}
	}
	// for(auto to : sol) cout << to.A << " " << to.B << endl;
	// 	cout << "-----" << endl;
	for(auto to : sol) solve(to);

	cout << -1 << endl;
    return 0;
}