#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define RREP(i , j , k) for(int i = j ; i >= k ; i --)
#define int long long
#define MAX 100900

int n , x[MAX] , r[MAX];
int ans[MAX];

int32_t main(){
	cin.tie(0) , cout.sync_with_stdio(0);
	cin >> n;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1) r[x[i]] = i;
	memset(ans , -1 , sizeof ans);
	RREP(i , n , 1){
		int idx = r[i] , ok = 0;
		// cout << "now = " << i << " " << idx << endl;
		for(int j = idx ; j <= n ; j += i){
			if(ans[j] == 0) ok = 1;
		}
		for(int j = idx ; j >= 1 ; j -= i){
			if(ans[j] == 0) ok = 1;
		}
		ans[idx] = ok;
	}
	REP(i , 1 , n + 1){
		if(ans[i] == 0) cout << "B";
		if(ans[i] == 1) cout << "A";
	}
	cout << endl;
	return 0;
}