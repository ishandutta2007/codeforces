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
#define MAX 300090
#define INF 0x3f3f3f3f

int n , x[MAX];
int ans[MAX];
int32_t main(){
	cin >> n;
	REP(i , n) cin >> x[i];
	int l , r;
	if(n % 2 == 0) l = n / 2 - 1 , r = n / 2;
	else l = n / 2 , r = n / 2 + 1;
	// DBGG(l , r);
	REP(i , n){
		int tn = n - i , tml , tmr;
		if(tn % 2 == 0) tml = tn / 2 - 1 , tmr = tn / 2 + i;
		else tml = tn / 2 , tmr = tn / 2 + i;
		if(i % 2 == 0){
		// DB4("i = " , i , tml , tmr);
			int tmp = 0;
			if(tn % 2 == 0){
				x[n] = -INF;
				while(tml <= l) tmp = max(tmp , max(x[l] , x[l + 1])) , l--;
				while(r < tmr) tmp = max(tmp , max(x[r] , x[r + 1])) , r++;
			}
			else {
				while(tml <= l){
					if(tn == 1) tmp = max(tmp , x[l]);
					else if(x[l] >= x[l - 1] && x[l] >= x[l + 1])
						tmp = max(tmp , max(x[l - 1] , x[l + 1]));
					else  tmp = max(tmp , x[l]);
					l --;
				}
				while(r <= tmr){
					if(tn == 1) tmp = max(tmp , x[r]);
					else if(x[r] >= x[r - 1] && x[r] >= x[r + 1])
						tmp = max(tmp , max(x[r - 1] , x[r + 1]));
					else tmp = max(tmp , x[r]);
					r ++;
				}
			}
			if(i > 1) ans[i] = max(tmp , ans[i - 2]);
			else ans[i] = tmp;
		}
	}

	// 	if(n % 2 == 0) l = n / 2 - 1 , r = n / 2;
	// else l = n / 2 , r = n / 2 ;


	if((n - 1) % 2 == 0) l = (n - 1) / 2 - 1 , r = (n - 1) / 2;
	else l = (n - 1) / 2 , r = (n - 1) / 2 + 1;
	// DB4("75" , " " , l , r);
	REP(i , n){
		int tn = n - i , tml , tmr;
		if(tn % 2 == 0) tml = tn / 2 - 1 , tmr = tn / 2 + i;
		else tml = tn / 2 , tmr = tn / 2 + i;
		if(i % 2 == 1){
		// DB4(i , tml , tmr , "80");
			int tmp = 0;
			if(tn % 2 == 0){
				x[n] = -INF;
				while(tml <= l) tmp = max(tmp , max(x[l] , x[l + 1])) , l--;
				while(r < tmr) tmp = max(tmp , max(x[r] , x[r + 1])) , r++;
			}
			else {
				while(tml <= l){
					if(tn == 1) tmp = max(tmp , x[l]);
					else if(x[l] >= x[l - 1] && x[l] >= x[l + 1])
						tmp = max(tmp , max(x[l - 1] , x[l + 1]));
					else  tmp = max(tmp , x[l]);
					l --;
				}
				while(r <= tmr){
					if(tn == 1) tmp = max(tmp , x[r]);
					else if(x[r] >= x[r - 1] && x[r] >= x[r + 1])
						tmp = max(tmp , max(x[r - 1] , x[r + 1]));
					else tmp = max(tmp , x[r]);
					r ++;
				}
			}
			if(i > 1) ans[i] = max(tmp , ans[i - 2]);
			else ans[i] = tmp;

		}
	}
	REP(i , n) ans[n - 1] = max(ans[n - 1] , x[i]);
	REP(i , n) cout << ans[i] << " " ; cout << endl;
    return 0;
}