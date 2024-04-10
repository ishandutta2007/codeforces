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
#define MAX 510
#define INF 0x3f3f3f3f

int n , m;
string p[MAX];
PII st , en;
int use[MAX][MAX] , Z[] = {-1 , 0 , 0 , 1} , z[] = {0 , -1 , 1 , 0};

class djs{
public:
	PII x[MAX][MAX];
	void init(){ REP(i , MAX) REP(j , MAX) x[i][j] = mp(i , j); }
	PII Find(PII now) { return now == x[now.A][now.B] ? now : x[now.A][now.B] = Find(x[now.A][now.B]); }
	void Union(PII u , PII v){ x[Find(u).A][Find(u).B] = Find(v); }
	PII operator[](const PII now){ return Find(now); }
}ds;
int solve(){
	ds.init();
	int tok = 0;
	p[st.A][st.B] = '.' , tok = 1;
	REP(i , n){
		REP(j , m){
			if(p[i][j] == 'X' || (en.A == i && en.B == j)) continue;
			REP(k , 4){
				int q = i + Z[k] , w = j + z[k];
            	if(q >= 0 && q < n && w >= 0 && w < m && p[q][w] == '.'){
            		if(q != en.A || w != en.B){
            			// DB4(i , j , q , w);
            			ds.Union(mp(i , j) , mp(q , w));
            		}
            	}
			}
		}
	}
	if(tok && st == en){
		REP(k , 4){
			int q = st.A + Z[k] , w = st.B + z[k];
        	if(q >= 0 && q < n && w >= 0 && w < m && p[q][w] == '.') return 1;
		}
		return 0;
	}
	else if(p[en.A][en.B] == 'X'){
		REP(k , 4){
			int q = en.A + Z[k] , w = en.B + z[k];
        	if(q >= 0 && q < n && w >= 0 && w < m && ds[mp(q , w)] == ds[st]) return 1;
		}
		return 0;
	}
	else {
		int tma = 0 , tmb = 0;
		REP(k , 4){
			int q = en.A + Z[k] , w = en.B + z[k];
        	if(q >= 0 && q < n && w >= 0 && w < m && ds[mp(q , w)] == ds[st]) tma = 1;
        	if(q >= 0 && q < n && w >= 0 && w < m && p[q][w] == '.') tmb ++;
		}
		if(tma > 0 && tmb > 1) return 1;
		return 0;
	}
}
int32_t main(){
	cin >> n >> m;
	REP(i , n) cin >> p[i];
	cin >> st.A >> st.B; st.A -- , st.B --;
	cin >> en.A >> en.B; en.A -- , en.B --;
	int ans = solve();
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
    return 0;
}