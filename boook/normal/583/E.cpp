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
#define LL long long
#define MAX 200005
#define INF 0x3f3f3f3f

int n , x[MAX] , use[MAX] , tma[MAX] , val[MAX];
VI v , b , cc[MAX];
PII fk[MAX];

void F(int now){
	v.clear();
	int r = -1 , l = 0;
	REP(i , n + 1){
		r++;
		if(i == n || use[i] != now){
			if(r - l != 0) v.pb(r - l);
			r = i , l = i + 1;
		}
	}
	if(v.size() > 1 && use[0] == now && use[n - 1] == now) v[0] += v.back() , v.pop_back();
}

int32_t main(){
	RI(n);
	REP(i , n) RI(x[i]);

	int mm = x[0];
	REP(i , n) mm = max(mm , x[i]);

	REP(i , n) if(mm == x[i]) use[i] = -1;
	
	F(-1);
	LL ans = 0;

	for(auto i : v) b.pb(i);

	if(n > 1 && v.size() == 1 && v[0] == n) ans += (LL)n * ((LL)n - 1);
	else if(n > 1) for(auto i : v) ans += ((LL)i * ((LL)i + 1)) / 2;
	

	REPNM(i , 2 , n) if(__gcd(i , n) != 1) val[__gcd(i , n)] ++ , cc[__gcd(i , n)].pb(i);

	REPNM(i , 2 , n){
		if(val[i] == 0) continue;
		MEM(tma , 0);

		REP(j , n) tma[j % i] = max(tma[j % i] , x[j]);
		REP(j , n) if(tma[j % i] == x[j]) use[j] = i;
		F(i);
		LL tmpans = 0;

		int tpo = 0;
		REPNM(j , 1 , n + 1){
			if(tpo < cc[i].size() && j == cc[i][tpo])
				fk[j] = mp(fk[j - 1].A + 1 , fk[j - 1].B + j - 1) , tpo ++;
			else fk[j] = fk[j - 1];
		}
		
		if(v.size() && v[0] == n) tmpans += (LL)n * (LL)cc[i].size();
		else for(auto j : v) if(j >= i) tmpans += (LL)j * fk[j].A - fk[j].B;
		if(b.size() && b[0] == n) tmpans -= (LL)n * (LL)cc[i].size();
		else for(auto j : b) if(j >= i) tmpans -= (LL)j * fk[j].A - fk[j].B;
		ans += tmpans;

	}
	printf("%lld\n", ans);
    return 0;
}