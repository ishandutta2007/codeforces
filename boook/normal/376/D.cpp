#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k)  for(int i = j ; i <  k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define MEM(i , j) memset(i , j , sizeof i)
#define pb push_back
#define MAX 5050
#define int long long
int n , m , x[MAX][MAX] , p[MAX];
string s[MAX];
int32_t main() {
    cin.tie(0) , cout.sync_with_stdio(0);
	cin >> n >> m;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 1 , n + 1) REP(j , 1 , m + 1){
	    x[i][j] = s[i - 1][j - 1] - '0';
	}
	RREP(i , n , 1) RREP(j , m , 1){
	    if(x[i][j]) x[i][j] += x[i][j + 1];
	}
//	REP(i , 1 , n + 1){
//	    REP(j , 1 , m + 1) cout << x[i][j] << " ";
//	    cout << endl;
//	}
	int ans = 0;
	REP(i , 1 , m + 1){
        MEM(p , 0);
        REP(j , 1 , n + 1) p[x[j][i]] ++;
        vector<int> sol;
        RREP(j , m , 1) while(p[j]--) sol.pb(j);
        REP(j , 0 , sol.size()){
//            cout << sol[j] << " " ;
            ans = max(ans , (j + 1) * sol[j]);
        }
//        cout << endl;
	}
	cout << ans << endl;
	return 0;
}