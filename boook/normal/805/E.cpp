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
#define MAX 600000
#define INF 0x3f3f3f3f

int n , m , use[MAX];
VI x[MAX] , g[MAX];
void DFS(int now , int fa){
	VI no;
	REP(i , x[now].size()){
		if(use[x[now][i]] != 0) no.pb(use[x[now][i]]);
	}
	sort(ALL(no));
	int val = 1 , po = 0;
	REP(i , x[now].size()){
		if(use[x[now][i]]) continue;
		while(po < no.size() && val == no[po]) val ++ , po++;
		use[x[now][i]] = val , val++;
	}
	for(auto i : g[now]){
		if(i == fa) continue;
		else DFS(i , now);
	}
}
int32_t main(){
	IOS;
	cin >> n >> m;
	int mm = 0 , st = 1;
	REPNM(i , 1 , n + 1){
		int tmp , tma;
		cin >> tmp;
		REP(j , tmp) cin >> tma , x[i].pb(tma);
		if(tmp > mm) mm = tmp , st = i;
	}
	REPNM(i , 1 , n) {
		int q , w;
		cin >> q >> w;
		g[q].pb(w) , g[w].pb(q);
	}
	int ans = max(mm , 1);
	DFS(st , -1);
	cout << ans << "\n";
	REPNM(i , 1 , m + 1){
		cout << use[i] + (use[i] == 0) << " " ;
	}
	cout << "\n";
    return 0;
}