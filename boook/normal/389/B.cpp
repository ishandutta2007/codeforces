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
#define MAX 200
#define INF 0x3f3f3f3f
#define debug 1

void Pre(){
	
}

void Init(){
	
}

void Read(){
	
}
string p[MAX];
int n;
int Z[] = {-1 , 0 , 0 , 1 , 0} , z[] = {0 , -1 , 1 , 0 , 0};
int F(int x , int y){
	REP(i , 5){
		int q = x + Z[i];
		int w = y + z[i];
		if(p[q][w] != '#') return 0;
		p[q][w] = '!';
	}
	return 1;
}
int Solve(){
	if(n < 3)return 0;
	REP(i , n - 2){
		if(p[i][0] == '#' || p[i][n - 1] == '#') return 0;
		REPNM(j , 1 , n - 1){
			if(p[i][j] == '#'){
				if(F(i + 1 , j) == 0) return 0; 
			}
		}
	}
	REP(i , n) if(p[n - 2][i] == '#') return 0;
	REP(i , n) if(p[n - 1][i] == '#') return 0;
	return 1;
}

int main(){
	
	while(cin >> n){
		REP(i , n) cin >> p[i];
		int ans = Solve();
		if(ans) puts("YES");
		else puts("NO");
	}
    return 0;
}