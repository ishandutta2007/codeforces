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
#define MAX 
#define INF 0x3f3f3f3f
#define debug 1

int x[10];
PII a , b , c;
char TR(PII now){
	if(now == mp(x[0] , x[1]) || now == mp(x[1] , x[0])){
		x[0] = x[1] = -1; return 'A';
	}
	if(now == mp(x[2] , x[3]) || now == mp(x[3] , x[2])){
		x[2] = x[3] = -1; return 'B';
	}
	if(now == mp(x[4] , x[5]) || now == mp(x[5] , x[4])){
		x[4] = x[5] = -1; return 'C';
	}
}
int Q(){
	if(a.A == b.A && b.A == c.A && a.B + b.B + c.B == a.A){
		cout << a.A << endl;
		char tmp = TR(a);
		REP(i , a.B){
			REP(j , a.A) cout << tmp;
			cout << endl;
		}
		tmp = TR(b);
		REP(i , b.B){
			REP(j , a.A) cout << tmp;
			cout << endl;
		}
		tmp = TR(c);
		REP(i , c.B){
			REP(j , a.A) cout << tmp;
			cout << endl;
		}
		return 1;
	}
	else return 0;
}

int F(){

	if(a.B == b.B + c.A && b.A == c.B && a.A + b.A == a.B){
		cout << a.B << endl;
		char tmp = TR(a);
		REP(i , a.A){
			REP(j , a.B) cout << tmp;
			cout << endl;
		}
		char tma = TR(b) , tmb = TR(c);
		REP(i , b.A){
			REP(j , a.B){
				if(j < b.B) cout << tma;
				else cout << tmb;
			}
			cout << endl;
		}
		return 1;
	}
	else return 0;
}
void Solve(){
	REPNM(i , 1 , 4) REPNM(j , 1 , 4) REPNM(k , 1 , 4){
		if(i == j || i == k || j == k) continue;
		REP(ii , 2) REP(jj , 2) REP(kk , 2){
			a = mp(x[i + i - 2] , x[i + i - 1]);
			b = mp(x[j + j - 2] , x[j + j - 1]);
			c = mp(x[k + k - 2] , x[k + k - 1]);
			if(ii) swap(a.A , a.B);
			if(jj) swap(b.A , b.B);
			if(kk) swap(c.A , c.B);
			if(Q()) return;
			if(F()) return;
		}
	}
	puts("-1");
}
int main(){
	REP(i , 6) RI(x[i]);
	Solve();
    return 0;
}