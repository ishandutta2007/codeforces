#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; ++ i)
#define int long long
#define MAX 200
int n , ans = 0 , x[MAX][MAX];
string s[MAX];
int32_t main(){
	cin >> n;
	REP(i , 0 , n) cin >> s[i];
	REP(i , 0 , n){
		int cnt = 0;
		REP(j , 0 , n) if(s[i][j] == 'C') cnt ++;
		ans += (cnt * (cnt - 1) / 2);
		cnt = 0;
		REP(j , 0 , n) if(s[j][i] == 'C') cnt ++;
		ans += (cnt * (cnt - 1) / 2);
	}
	cout << ans << endl;
	return 0;
}