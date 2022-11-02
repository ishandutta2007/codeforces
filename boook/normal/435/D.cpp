/*input
3 5
10000
10010
00001
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 500
#define INF 0x3f3f3f3f
#define N 450

PII operator + (PII a , PII b){ return mp(a.A + b.A , a.B + b.B); }

int n , m , x[MAX][MAX] , h[MAX][MAX] , w[MAX][MAX];
int l[MAX + MAX][MAX] , r[MAX + MAX][MAX];
string s[MAX];

PII X[] = {mp(1 , 1) , mp(-1 , -1) , mp(1 , -1) , mp(-1 , 1)
 , mp(0 , 1) , mp(-1 , 0) , mp(0 , -1) , mp(0 , 1)};
PII Y[] = {mp(-1 , 1) , mp(1 , -1) , mp(1 , 1) , mp(-1 , -1)
 , mp(1 , 0) , mp(0 , -1) , mp(1 , 0) , mp(-1 , 0)};
int IN(PII now){ return 1 <= now.A && now.A <= n && 1 <= now.B && now.B <= m; }
int check(PII a , PII b){
	if(a.B == b.B && a.A > b.A) swap(a , b);
	if(a.B != b.B && a.B > b.B) swap(a , b);
	if(a.A == b.A) return w[b.A][b.B] - w[a.A][a.B - 1];
	if(a.B == b.B) return h[b.A][b.B] - h[a.A - 1][a.B];
	// DB4(a.A , a.B , b.A , b.B);
	if(b.A > a.A && b.B > a.B){
		int line = a.A - a.B + N;
		return r[line][b.B] - r[line][a.B - 1];
	}
	else {
		int line = a.A + a.B;
		return l[line][b.B] - l[line][a.B - 1];
	}
} 
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) x[i][j] = s[i - 1][j - 1] == '1';
	
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) h[i][j] = x[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) w[i][j] = x[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) l[i + j][j] = x[i][j];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) r[i - j + N][j] = x[i][j];

	REP(i , 1 , MAX) REP(j , 1 , MAX) h[i][j] += h[i - 1][j];
	REP(i , 1 , MAX) REP(j , 1 , MAX) w[i][j] += w[i][j - 1];
	REP(i , 1 , MAX * 2) REP(j , 1 , MAX) l[i][j] += l[i][j - 1];
	REP(i , 1 , MAX * 2) REP(j , 1 , MAX) r[i][j] += r[i][j - 1];
	long long ans = 0;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1){
		// REP(k , 5 , 6){
		REP(k , 0 , 8){
			PII a = mp(i , j);
			PII b = a + X[k];
			PII c = a + Y[k];
			while(IN(b) && IN(c)){
				if(check(a , b) == 0 && check(b , c) == 0 && check(c , a) == 0){
					// DBGG(a.A , a.B);
					// DBGG(b.A , b.B);
					// DBGG(c.A , c.B);
					// cout << "----" << endl;
					ans ++;
				}
				b = b + X[k];
				c = c + Y[k];
			}
		}
	}
	cout << ans << endl;
    return 0;
}