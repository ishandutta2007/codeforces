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
#define MAX 1010
#define INF 0x3f3f3f3f

int n , m;
PII st , en;
string p[MAX];
int use[MAX][MAX] , z[] = {-1 , 1 , 0 , 0} , Z[] = {0 , 0 , 1 , -1};
int solve(){

	REP(i , 4){
		PII now = st;
		while(1){
			now.A += z[i] , now.B += Z[i];
			if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m && p[now.A][now.B] == '.')
				use[now.A][now.B] = 1;
			else break;
		}
	}
	if(use[en.A][en.B] != 0) return 1;

	MEM(use , 0);

	REP(i , 2){
		PII now = st;
		use[now.A][now.B] = 1;
		while(1){
			now.A += z[i] , now.B += Z[i];
			if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m && p[now.A][now.B] == '.')
				use[now.A][now.B] = 1;
			else break;
		}
	}
	REP(i , 2){
		PII now = en;
		use[now.A][now.B] = 1;
		while(1){
			now.A += z[i] , now.B += Z[i];
			if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m && p[now.A][now.B] == '.')
				use[now.A][now.B] = 1;
			else break;
		}
	}
	

	if(st.B != en.B){
		int ok = 0 , q = min(st.B , en.B) , w = max(st.B , en.B);
		REP(i , n){
			if(use[i][q] == 0 || use[i][w] == 0) continue;
			int tok = 1;
			REPNM(j , q , w + 1){
				if(p[i][j] == '*') tok = 0;
			}
			if(tok) ok = 1;
		}
		if(ok) return 1;
	}
	
	MEM(use , 0);

	REPNM(i , 2 , 4){
		PII now = st;
		use[now.A][now.B] = 1;
		while(1){
			now.A += z[i] , now.B += Z[i];
			if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m && p[now.A][now.B] == '.') use[now.A][now.B] = 1;
			else break;
		}
	}
	REPNM(i , 2 , 4){
		PII now = en;
		use[now.A][now.B] = 1;
		while(1){
			now.A += z[i] , now.B += Z[i];
			if(now.A >= 0 && now.A < n && now.B >= 0 && now.B < m && p[now.A][now.B] == '.') use[now.A][now.B] = 1;
			else break;
		}
	}
	// REP(i , n) {REP(j , m) cout << use[i][j]; cout << endl;}
	if(st.A != en.A){
		int ok = 0 , q = min(st.A , en.A) , w = max(st.A , en.A);
		REP(j , m){
			if(use[q][j] == 0 || use[w][j] == 0) continue;
			int tok = 1;
			REPNM(i , q , w + 1){
				if(p[i][j] == '*') tok = 0;
			}
			if(tok) ok = 1;
		}
		if(ok) return 1;
	}

	return 0;
}
int main(){
	cin >> n >> m;
	REP(i , n) cin >> p[i];

	REP(i , n){
		REP(j , m){
			if(p[i][j] == 'S') st = mp(i , j);
			if(p[i][j] == 'T') en = mp(i , j);
		}
	}

	int ans = solve();
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}