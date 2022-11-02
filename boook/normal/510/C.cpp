#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int LL;
typedef pair<int,int> PII;
typedef pair<LL , LL> PLL;
typedef pair< LL , LL > PLL;
typedef vector< int > VI;
typedef vector< LL > VLL;
typedef vector< PII > VPII;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define LREP(i,j)      for(LL  i = 0 ; i < j ; i++)
#define LREPNM(i,j,k)  for(LL  i = j ; i < k ; i++)
#define LRREP(i,j,k)   for(LL  i = j ; i >=k ; i--)
#define pb   push_back
#define mp   make_pair
#define A    first
#define B    second
#define MEM(i,j)   memset(i,j,sizeof i)
#define ALL(i)     i.begin(),i.end()
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
#define MAX 30
#define INF 0x3f3f3f3f

VI v[MAX] , g;
int use[MAX];
int DFS1(int now , int root){
	use[now] = 1;
	int tmp = 0;
	for(auto i : v[now]){
		if(use[i] && i == root) return 1;
		else if(use[i] == 0) tmp = max(tmp , DFS1(i , root));
	}
	return tmp;
}
void DFS2(int now , int fa){
	use[now] = 1;
	for(auto i : v[now]){
		if(i == fa) continue;
		if(use[i] == 0)DFS2(i , now);
	}
	g.pb(now);
}
int main(){
    string a , b;
    int n;
    cin >> n >> a;
	int ok = 1;
    REPNM(i , 1 , n){
    	cin >> b;
    	int len = min(a.size() , b.size());
    	int fk = 1;
    	REP(j , len){
    		if(a[j] != b[j]){
    			v[a[j] - 'a'].pb(b[j] - 'a');
    			fk = 0;
    			break;
    		}
    	}
    	if(fk && a.size() > b.size()) ok = 0;
    	a = b;
    }
	REP(i , MAX) if(!use[MAX] && DFS1(i , i)) ok = 0;
	if(!ok) puts("Impossible");
	else {
		MEM(use , 0);
		REP(i , 26) if(!use[i]) DFS2(i , -1);
		RREP(i , g.size() - 1 , 0) cout << char(g[i] + 'a') ;
		cout << endl;
	}
    
    return 0;
}