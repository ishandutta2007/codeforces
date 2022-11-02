#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
#define DB()          if(debug)
#define DBGG(i,j)     if(debug) cout<<i<<" "<<j<<endl;
#define DB4(i,j,k,l)  if(debug) cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
#define RI(i)       scanf("%d",&i)
#define RII(i,j)    scanf("%d%d",&i,&j)
#define RIII(i,j,k) scanf("%d%d%d",&i,&j,&k)
#define RL(i)       scanf("%lld",&i)
#define RLL(i,j)    scanf("%lld%lld",&i,&j)
#define RLLL(i,j,k) scanf("%lld%lld%lld",&i,&j,&k)
///---------------------------
#define MAX 200
#define INF 0x3f3f3f3f
#define debug 1

string s[MAX];
int g[MAX][4];

int F(char now){
	if(now == '#' || now == '*' || now == '&')return 0;
	else if('0' <= now && now <= '9') return 1;
	else return 2;
}
int main(){
	int n , m;
	while(cin >> n >> m){

		MEM(g , INF);

		REP(i , n) cin >> s[i];
		REP(i , n){
			REP(j , s[i].size()){
				char now = s[i][j];
				int tmp = F(now);
				g[i][tmp] = min(g[i][tmp] , min(j , m - j));
			}
		}

		// REP(i , n) cout << g[i][0] << " " << g[i][1] << " " << g[i][2] << endl;

		int ans = INF;
		REP(i , n){
			REP(j , n){
				REP(k , n){
					if(i == j || j == k || i == k)continue;
					int a = g[i][0];
					int b = g[j][1];
					int c = g[k][2];
					if(a == INF || b == INF || c == INF) continue;
					ans = min(ans , a + b + c);
				}
			}
		}
		cout << ans << endl;
	}
    return 0;
}