#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)  for(int i = j ; i < k ; i++)
#define RREP(i,j,k)   for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout << i << " " << j << endl;
#define DB4(i,j,k,l)  if(debug) cout << i << " " << j << " " << k << " " << l <<endl;
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0);
///------------------------------------------------------------
#define MAX 500
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){}

void Init(){}
int n , m , k;
string s[MAX];
int use[MAX][MAX];
vector<PII> good;
int z[] = {-1 , 0 , 0 , 1} , Z[] = {0 , -1 , 1 , 0};
void DFS(int x , int y){
	REP(i , 4){
		int q = x + z[i];
		int w = y + Z[i];
		if(q >= 0 && q < n && w >= 0 && w < m && s[q][w] == '.' && use[q][w] == 0){
			use[q][w] = 1;
			DFS(q , w);
		}
	}
	good.pb(mp(x , y));
}
int main(){
	cin >> n >> m >> k;
	REP(i , n) cin >> s[i];
	REP(i , n) {
		int ok = 0;
		REP(j , m) {
			if(s[i][j] == '.'){
				use[i][j] = 1;
				DFS(i , j);				// REP(k , 4){
				// 	int qq = i + z[k];
				// 	int ww = j + Z[k];
				// 	if(qq >= 0 && qq < n && ww >= 0 && ww < m 
				// 		&& s[qq][ww] == '.' && use[qq][ww] == 0){
				// 		DFS(qq , ww);
				// 	}
				// }
				// good.pb(mp(i , j));
				ok = 1;
				break;
			}
		}
		if(ok)break;
	}
	REP(i , k){
		PII now = good[i];
		s[now.A][now.B] = 'X';
	}
	REP(i , n) cout << s[i] << endl;
    return 0;
}