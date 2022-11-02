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
#define MAX 400
#define INF 0x3f3f3f3f
int fk;
int n;
PII x[MAX];
int G(PII a , PII b , PII c){
	PII q = mp(b.A - a.A , b.B - a.B);
	PII w = mp(c.A - a.A , c.B - a.B);
	return q.A * w.B - q.B * w.A;
}
int F(PII a , PII b , PII c){
	return (G(a , b , c) > 0);	
}
int main(){

	RI(n);
	REP(i , n) RII(x[i].A , x[i].B);

	int ans = 0;

    REP(i , n) REP(j , n){

    	if(i == j) continue;

    	int a = -1 , b = -1;
    	REP(k , n){
    		if(i == k || j == k) continue;
    		int ty = F(x[i] , x[j] , x[k]);

    		int dis = abs(G(x[i] , x[j] , x[k]));
    		if(ty == 0) a = max(a , dis) ;
    		else b = max(b , dis) ;
    	}
    	if(a != -1 && b != -1){
    		ans = max(ans , a + b);
    	}
    }
    double tmp = ans;
	printf("%f\n", tmp / 2);
    return 0;
}