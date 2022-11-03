#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

const int mod = (int)1e9 + 7;

int n, d;


int mult(int a, int b){
	return a * (ll)b % mod;
}

int sum(int a, int b){
	int ans = a + b;
	if (ans >= mod) ans -= mod;
	if (ans < 0) ans += mod;
	return ans;
}

int bp(int a, int k){
	if (k == 0) return 1;
	if (k == 1) return a % mod;
	if (k % 2 == 0){
		int ans = bp(a, k / 2);
		return mult(ans, ans);
	} else {
		return mult(a, bp(a, k - 1));
	}
}

int inv(int x){
	return bp(x, mod - 2);
}

int dp[5002][5002];

int step2[5002];
int fac[5002];
int fac2[5002];

int cnk(int val){
	if (val == n) return 1;
	return mult(fac2[val], inv(fac[val]));
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d;
    int ans = 0;

    dp[1][1] = 1;

    for (int i = 2; i < 5002; i++){
    	for (int j = 1; j <= i; j++){
    		dp[i][j] = sum(dp[i - 1][j - 1], mult(dp[i - 1][j], j));
    	}
    }

    step2[0] = 1;
    for (int i = 1; i < 5002; i++) step2[i] = mult(step2[i - 1], 2);
    fac[0] = 1;
	for (int i = 1; i < 5002; i++) fac[i] = mult(fac[i - 1], i);
	fac2[1] = n;
	for (int i = 2; i < 5002; i++){
		if (n - i + 1 <= 0) break;
 		fac2[i] = mult(fac2[i - 1], n - i + 1);
	}

	//cout << dp[3][1] << endl;

    for (int i = 1; i <= min(n, d); i++){
    	ans = sum(ans, mult(fac[i], mult(dp[d][i], mult(cnk(i), bp(2, n - i)))));
    }

    cout << ans;
}