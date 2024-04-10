#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i++)
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
//--------------------------------------
#define MAX 1010

int n , k , x[MAX] , dp[MAX * MAX];

int main(){
	IOS;
	cin >> n >> k;
	REP(i , 1 , n + 1) cin >> x[i];
	sort(x + 1 , x + 1 + n);
	REP(i , 2 , n + 1) x[i] -= x[1];
	REP(i , 1 , x[n] * k + 1) dp[i] = k + 1;
	REP(i , 2 , n + 1){
		REP(j , x[i] , x[n] * k + 1){
			dp[j] = min(dp[j] , dp[j - x[i]] + 1);
		}
	}
	REP(i , 0 , x[n] * k + 1){
		if(dp[i] <= k){
			cout << i + x[1] * k << " ";
		}
	}
	cout << endl;
	return 0;
}