#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define LL long long int
#define PII pair<int , int>
#define PLL pair< LL , LL >
#define VI vector< int > 
#define VLL vector< LL > 
#define VPII vector< PII >
#define VPLL vector< PLL >
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
#define int long long
#define MAX 100900
#define INF 0x3f3f3f3f
typedef pair<long double , long double> PDD;
int n;
int x[MAX][4] , use[MAX];
long double dd[MAX][4];
PDD t[MAX];

int32_t main(){
	cin >> n;
	REP(i , n + 1) REP(j , 4) cin >> x[i][j] , dd[i][j] = x[i][j];

	int ok = 1 , a = x[0][0] , b = x[0][1] , c = x[0][2] , d = x[0][3];

	REPNM(i , 1 , n + 1){
		if(x[i][2] == 0 && x[i][3] == 0){
			if(a < x[i][0] && x[i][0] < c && b < x[i][1] && x[i][1] < d) use[i] = 1;
			else ok = 0;
		}
		else if(x[i][2] == 0){
			if(a < x[i][0] && x[i][0] < c){
				long double tma = ((long double)b - dd[i][1]) / dd[i][3] , tmb = ((long double)d - dd[i][1]) / dd[i][3];
				if(tma < 0 && tmb < 0) ok = 0;
				else{
					t[i] = mp(fmin(tma , tmb) , fmax(tma , tmb));
					if(t[i].A < 0) t[i].A = 0;
				}
			}else ok = 0;
		}
		else if(x[i][3] == 0){
			if(b < x[i][1] && x[i][1] < d){
				long double tma = ((long double)a - dd[i][0]) / dd[i][2] , tmb = ((long double)c - dd[i][0]) / dd[i][2];
				if(tma < 0 && tmb < 0) ok = 0;
				else{
					t[i] = mp(fmin(tma , tmb) , fmax(tma , tmb));
					if(t[i].A < 0) t[i].A = 0;
				}
			}else ok = 0;
		}
		else {
			long double tma = ((long double)b - dd[i][1]) / dd[i][3] , tmb = ((long double)d - dd[i][1]) / dd[i][3];
			if(tma < 0 && tmb < 0) ok = 0;
			else t[i] = mp(fmin(tma , tmb) , fmax(tma , tmb));				


			tma = ((long double)a - dd[i][0]) / dd[i][2] , tmb = ((long double)c - dd[i][0]) / dd[i][2];
			if(tma < 0 && tmb < 0) ok = 0;
			else t[i].A = fmax(t[i].A , fmin(tma , tmb)) , t[i].B = fmin(t[i].B , fmax(tma , tmb));
			if(t[i].A < 0) t[i].A = 0;
			if(t[i].A >= t[i].B) ok = 0;
		}
	}

	if(ok == 0){
		cout << -1 << endl;
		return 0;
	}

	long double sml = 0 , big = 2;
	int qqq = 1;
	REPNM(i , 1 , n + 1){
		if(use[i]) continue;
		if(qqq) sml = t[i].A , big = t[i].B , qqq = 0;
		else sml = fmax(sml , t[i].A) , big = fmin(big , t[i].B);
	}
	if(sml >= big) cout << -1 << endl;
	else printf("%.09Lf\n", sml);
    return 0;
}