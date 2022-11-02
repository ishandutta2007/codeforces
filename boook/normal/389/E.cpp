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

void Solve(){}

int n;
vector<int> v[MAX];

int main(){
	RI(n);
	vector<int> tmp;
	int a = 0 , b = 0;
	REP(i , n) {
		int q , w;
		RI(q);
		REP(j , q) RI(w) , v[i].pb(w);
		REP(j , q / 2) a += v[i][j] , b += v[i][q - 1 - j];
		if(q & 1) tmp.pb(v[i][q / 2]);
	}
	sort(ALL(tmp));
	int now = 0;
	RREP(i , tmp.size() - 1 , 0){
		if(now == 0) a += tmp[i];
		else b += tmp[i];
		now = 1 - now;
	} 
	cout << a << " " << b << endl;
    return 0;
}