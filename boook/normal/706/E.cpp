#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m , k;
int val[MAX][MAX];
PII d[MAX][MAX] , r[MAX][MAX];
void solveinit(){
	REP(i , 0 , n + 1) REP(j , 0 , m + 1)
		d[i][j] = mp(i + 1 , j);
	REP(i , 0 , n + 1) REP(j , 0 , m + 1)
		r[i][j] = mp(i , j + 1);
}
void R(PII &now){ now = r[now.A][now.B]; }
void D(PII &now){ now = d[now.A][now.B]; }
void SR(PII a , PII b){  swap(r[a.A][a.B] , r[b.A][b.B]);  }
void SD(PII a , PII b){  swap(d[a.A][a.B] , d[b.A][b.B]);  }
void solve(int a , int b , int x , int y , int H , int W){
	PII q[2] , w[2] , e[2] , r[2];
	PII now = mp(a - 1 , 0) , to = mp(x - 1 , 0);
	REP(i , 0 , b - 1) R(now);
	REP(i , 0 , y - 1) R(to);
	q[0] = now , q[1] = to;
	w[0] = now , w[1] = to;
	REP(i , 0 , W) R(w[0]) , R(w[1]) , SD(w[0] , w[1]);
	REP(i , 0 , H) D(q[0]) , D(q[1]) , SR(q[0] , q[1]);

	REP(i , 0 , H) D(w[0]) , D(w[1]) , SR(w[0] , w[1]);
	REP(i , 0 , W) R(q[0]) , R(q[1]) , SD(q[0] , q[1]);
}
void print(){
	REP(i , 1 , n + 1){
		PII pre = mp(i , 0);
		REP(j , 1 , m + 1){
			PII now = r[pre.A][pre.B];
			cout << val[now.A][now.B] << " ";
			pre = now;
		}
		cout << endl;
	}
}
int32_t main(){
	IOS;
	cin >> n >> m >> k;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) cin >> val[i][j];

	solveinit();

	REP(i , 1 , k + 1){
		int q , w , e , a , b , c;
		cin >> q >> w >> e >> a >> b >> c;
		solve(q , w , e , a , b , c);
	}
	print();
    return 0;
}