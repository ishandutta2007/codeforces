#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

const ll LINF = (ll)8e18 + 7;

int n;
int p, q, r;
int a[100007];
ll dp[100007][4];

int main(){ 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> p >> q >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp[0][0] = 0;
	dp[0][1] = -LINF;
	dp[0][2] = -LINF;
	dp[0][3] = -LINF;

	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 3; j++){
			dp[i][j] = dp[i - 1][j];
		}
		dp[i][1] = max(dp[i][1], dp[i][0] + p * (ll)a[i]);
		dp[i][2] = max(dp[i][2], dp[i][1] + q * (ll)a[i]);
		dp[i][3] = max(dp[i][3], dp[i][2] + r * (ll)a[i]);
	}

    cout << dp[n][3];
}