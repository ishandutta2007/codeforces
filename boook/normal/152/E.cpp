/*input
4 5 4
1 4 5 1 2
2 2 2 2 7
2 4 1 4 5
3 2 1 7 1
1 1
1 5
4 1
4 4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mmp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 110
#define INF 200009
#define PIII pair<PII , PII>

int n , m , k , x[MAX][MAX] , dis[MAX][MAX][150] , ok[MAX][MAX];
PIII pa[MAX][MAX][150];
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , -1 , 1 , 0};
PIII mp(int a , int b , int c , int d){
	return mmp(mmp(a , b) , mmp(c , d));
}
int32_t main(){
	
	IOS , cin >> n >> m >> k;

	MEM(dis , INF);
	priority_queue<PIII , vector<PIII> , greater<PIII>> pq;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1){
		cin >> x[i][j];
		dis[i][j][0] = x[i][j];
	}
	REP(i , 0 , k){
		int a , b; cin >> a >> b;
		dis[a][b][(1 << i)] = x[a][b];
		pq.push(mp(x[a][b] , (1 << i) , a , b));
	}
	int ans = INF;
	PIII id;
	while(pq.size()){
		PII pat = pq.top().A;
		PII now = pq.top().B;
		pq.pop();
		if(pat.B == (1 << k) - 1 && pat.A < ans){
			ans = pat.A;
			id = mp(now.A , now.B , pat.B , 0);
		}
		if(dis[now.A][now.B][pat.B] != pat.A) continue;
		// DB4(pat.A , pat.B , now.A , now.B);
		REP(i , 0 , 4){
			int tox = now.A + X[i];
			int toy = now.B + Y[i];
			if(1 <= tox && tox <= n && 1 <= toy && toy <= m);
			else continue;
			REP(j , 0 , (1 << k)){
				if(pat.B & j) continue;
				if(dis[tox][toy][pat.B | j] > pat.A + dis[tox][toy][j]){
					dis[tox][toy][pat.B | j] = pat.A + dis[tox][toy][j];
					pa[tox][toy][pat.B | j] = mp(now.A , now.B , pat.B , 0);
					pq.push(mp(dis[tox][toy][pat.B | j] , pat.B | j , tox , toy));
				}
			}
		}
	}
	queue<PIII> qu;
	qu.push(id);
	while(qu.size()){
		PII now = qu.front().A;
		PII pat = qu.front().B;
		qu.pop();
		ok[now.A][now.B] = 1;
		// DB4(now.A , now.B , pat.A , pat.B);
		if(pa[now.A][now.B][pat.A] == mp(0 , 0 , 0 , 0)) continue;
		else {
			qu.push(pa[now.A][now.B][pat.A]);
			qu.push(mp(now.A , now.B , pat.A ^ pa[now.A][now.B][pat.A].B.A , 0));
		}
	}
	// DBGG("ans = " , ans);
	cout << ans << endl;
	REP(i , 1 , n + 1){
		REP(j , 1 , m + 1){
			if(ok[i][j]) cout << "X";
			else cout << ".";
			// cout << ok[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}