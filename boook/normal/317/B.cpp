/*input
6 5
0 -2
0 -1
0 0
0 1
0 2
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
#define MAX 3030
#define INF 0x3f3f3f3f
#define N 1000

int cc[MAX][MAX] , inq[MAX][MAX];
// map<PII , int> cc;
// set<PII> inq;
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
int n , m;
int32_t main(){
	IOS , cin >> n >> m;
	queue<PII> pq;
	pq.push(mp(N , N));
	// cc[mp(0 , 0)] = 30000;
	cc[N][N] = n;
	int cnt = 0;
	// int aa = 0 , bb = 0;
	while(pq.size()){
		PII now = pq.front(); pq.pop();
		cnt ++;
	// if(cnt % 100000 == 0) DBGG("cnt = " , cnt);
	// aa = max(aa , abs(now.A - N));
	// bb = max(bb , abs(now.B - N));
	// if(aa > 1500 || bb > 1500){
	// 	cout << "break" << endl;
	// 	exit(0);
	// }
		// inq.erase(now);
		inq[now.A][now.B] = 0;
		int val = cc[now.A][now.B];
		if(val / 4 == 0) continue;
		// DB4(now.A , now.B , val , "");
		cc[now.A][now.B] = val % 4;

		REP(i , 0 , 4){
			int tox = now.A + X[i] , toy = now.B + Y[i];
			cc[tox][toy] += val / 4;
			if(inq[tox][toy] == 0){
				inq[tox][toy] = 1;
				// inq.insert(mp(tox , toy));
				pq.push(mp(tox , toy));
			}
		}
	}
	REP(i , 0 , m){
		int a , b;
		cin >> a >> b;
		if(a + N < 0 || a + N > 2000) cout << 0 << endl;
		else if(b + N < 0 || b + N > 2000) cout << 0 << endl;
		else cout << cc[a + N][b + N] << endl;
	}
	// DB4("aa = " , aa , "bb = " , bb);
    return 0;
}