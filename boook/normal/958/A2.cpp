/*input
10 5
somer
andom
noise
mayth
eforc
ebewi
thyou
hctwo
again
noise
somermayth
andomeforc
noiseebewi
againthyou
noisehctwo
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 2020
#define INF 0x3f3f3f3f
#define AC 10430579
#define mod 1000000007LL

int n , m , h[MAX * MAX] , id[MAX][MAX] , pos = 1 , c[MAX][MAX] , d[MAX][MAX];
string a[MAX] , b[MAX];
int32_t main(){
	IOS;
	cin >> n >> m;
	h[0] = 1;
	REP(i , 1 , MAX) REP(j , 1 , MAX) id[i][j] = pos ++;
	REP(i , 1 , MAX * MAX) h[i] = h[i - 1] * AC % mod;
	REP(i , 1 , n + 1) cin >> a[i] , a[i] = " " + a[i];
	REP(i , 1 , m + 1) cin >> b[i] , b[i] = " " + b[i];

	REP(i , 1 , n + 1) REP(j , 1 , m + 1) c[i][j] = a[i][j] * h[id[i][j]] % mod;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) c[i][j] = (c[i][j] + c[i][j - 1]) % mod;
	REP(i , 1 , n + 1) REP(j , 1 , m + 1) c[i][j] = (c[i][j] + c[i - 1][j]) % mod;


	REP(i , 1 , m + 1) REP(j , 1 , n + 1) d[i][j] = b[i][j] * h[id[i][j]] % mod;
	REP(i , 1 , m + 1) REP(j , 1 , n + 1) d[i][j] = (d[i][j] + d[i][j - 1]) % mod;
	REP(i , 1 , m + 1) REP(j , 1 , n + 1) d[i][j] = (d[i][j] + d[i - 1][j]) % mod;

	// REP(i , 1 , n + 1){REP(j , 1 , n + 1) cout << id[i][j] << " ";cout << endl; }

	REP(i , 0 , n) REP(j , 0 , n){
		if(i + m > n || j + m > n) continue;
		int v1 = c[i + m][m] + c[i][0] - c[i][m] - c[i + m][0];
		int v2 = d[m][j + m] + d[0][j] - d[m][j] - d[0][j + m];
		v1 = (v1 % mod + mod) % mod;
		v2 = (v2 % mod + mod) % mod;
		int gap = abs(id[i + 1][1] - id[1][j + 1]);
		v2 = (v2 * h[gap]) % mod;
		// DB4(i + 1 , j + 1 , v1 , v2);
		if(v1 == v2){
			cout << i + 1 << " " << j + 1 << endl;
			return 0;
		}
	}
	cout << "no answer" << endl;
    return 0;
}