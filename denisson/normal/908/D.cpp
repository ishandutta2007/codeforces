#include <bits/stdc++.h>
                     
using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

const int mod = (int)1e9 + 7;

int sum(int a, int b){
	int ans = a + b;
	if (ans >= mod) ans -= mod;
	return ans;
}

int sub(int a, int b){
	int ans = a - b;
	if (ans < 0) ans += mod;
	return ans;
}

int mult(int a, int b){
	return a * (ll)b % mod;
}

int bp(int a, int k){
	if (k < 0) k += mod - 1;
	if (k == 0) return 1;
	if (k % 2 == 1){
		return mult(a, bp(a, k - 1));
	} else {
		int q = bp(a, k / 2);
		return mult(q, q);
	}
}

int seq(int fr, int sh){
	return mult(fr, bp(sub(1, sh), -1));
}

int n, a, b;

int dp[1005][1005];

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> a >> b;
    int p1 = mult(a, bp(sum(a, b), -1));
    int p2 = mult(b, bp(sum(a, b), -1));
    dp[1][0] = 1;
    int ans = 0;
    for (int i = 1; i < 1005; i++) for (int j = 0; j < 1005; j++) if (dp[i][j]){
    	if (i + j >= n){
    		int val = i + j;
    		ans = sum(ans, mult(mult(dp[i][j], p2), sum(mult(val, seq(1, p1)), mult(seq(p1, p1), bp(sub(1, p1), -1)))));
    	} else {	
    		dp[i + 1][j] = sum(dp[i + 1][j], mult(dp[i][j], p1));
    		dp[i][i + j] = sum(dp[i][i + j], mult(dp[i][j], p2));
    	}
    }
    cout << ans;
}