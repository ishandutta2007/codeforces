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
#define MAX 100900
#define INF 0x3f3f3f3f
#define debug 1

int c[MAX] , ifm[MAX];
vector<int> v[MAX];
int ans ;
void DFS1(int now , int fa){
	ifm[now] = 0;
	REP(i , v[now].size()){
		int to = v[now][i];
		if(to == fa) continue;
		DFS1(to , now);
		if(ifm[to] == 1 || c[to] != c[now]) ifm[now] = 1;
	}
}
void DFS2(int now , int fa , int cannxt){
	int tmp = 0;
	REP(i , v[now].size()){
		int to = v[now][i];
		if(to != fa && ifm[to] == 1) tmp++;
	}
	// DBGG(now , tmp);
	if(tmp > 1){ ans = -2 ; return ; }
	else if(tmp == 0){ ans = now ; return ; }
	else {
		int nxt , can = 1;
		REP(i , v[now].size()){
			int to = v[now][i];
			if(to == fa) continue;
			else if(ifm[to] == 1) nxt = to;
			else if(c[to] != c[now]) can = 0;
		}
		if(can == 0){ ans = -2 ; return ; }
		else if(cannxt == 0){ ans = -2 ; return ; }
		else if(c[nxt] == c[now]) DFS2(nxt , now , 1);
		else DFS2(nxt , now , 0);
	}
}
int main(){
	int t;
	RI(t);

	int q , w;
	REP(i , t - 1){
		RII(q , w);
		v[q].pb(w);
		v[w].pb(q);
	}
	REPNM(i , 1 , t + 1) RI(c[i]);

	DFS1(1 , -1);
	ans = -1;
	DFS2(1 , -1 , 1);
	if(ans < 0) puts("NO");
	else printf("YES\n%d\n", ans);
    return 0;
}