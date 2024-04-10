#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 2010
#define INF 0x3f3f3f3f

int n , m;
string p[MAX];
int Z[] = {-1 , 0 , 1 , 0 , -1} , z[] = {0 , -1 , 0 , 1 , 0};
int inside(PII now){
	if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m) return 1;
	return 0;
}
int check(PII now){
	REP(i , 4){
		PII q = mp(now.A + Z[i] , now.B + z[i]);
		PII w = mp(now.A + Z[i + 1] , now.B + z[i + 1]);
		PII e = mp(now.A + Z[i] + Z[i + 1] , now.B + z[i] + z[i + 1]);
		if(inside(q) && inside(w) && inside(e)){
			if(p[q.A][q.B] == '.' && p[w.A][w.B] == '.' && p[e.A][e.B] == '.') return 1;
		}
	}
	return 0;
}
void solve(){
	queue<PII> qu;
	REP(i , n) REP(j , m){
		if(p[i][j] == '*') qu.push(mp(i , j));
	}
	while(qu.size()){
		PII now = qu.front(); qu.pop();
		if(p[now.A][now.B] == '.') continue;
		if(check(now)){
			p[now.A][now.B] = '.';
			REPNM(i , -1 , 2){
				REPNM(j , -1 , 2){
					int a = now.A + i , b = now.B + j;
					if(inside(mp(a , b)) && p[a][b] == '*') qu.push(mp(a , b));
				}
			}
		}
	}
}
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , n) cin >> p[i];
	solve();
	REP(i , n) cout << p[i] << "\n" ;
    return 0;
}