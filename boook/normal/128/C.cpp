#include <bits/stdc++.h> 
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define pb push_back
#define ALL(i) i.begin() , i.end()
///---------------------
#define int long long
#define MAX 3030
#define INF 0x3f3f3f3f
#define mod 1000000007LL
using namespace std;

int n , m , k , c[MAX][MAX];
signed main(){
	REP(i , 0 , MAX) REP(j , 0 , i + 1){
		if(j == 0 || j == i) c[i][j] = 1;
		else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	cin >> n >> m >> k;
	if(n < 2 || m < 2) return cout << 0 << endl , 0;
	int v1 = (c[n - 2][k + k] + c[n - 2][k + k - 1]) % mod;
	int v2 = (c[m - 2][k + k] + c[m - 2][k + k - 1]) % mod;
	cout << v1 * v2 % mod << endl;
	return 0;
}