#include <bits/stdc++.h>
					
using namespace std;
			
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()

const int mod = (int)1e9 + 7;

int n;
string ss;
int dp[5002][5002][2];

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

int main(){
//	freopen("input.txt", "r", stdin);
	//freopen("output1.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		ss += c;
	}
	//cout << ss << endl;
	dp[0][0][0] = 1;
	for (int i = 0; i < ss.size(); i++) for (int s = 5001; s >= 0; s--) for (int g = 0; g < 2; g++) if (dp[i][s][g] > 0){
		//cout << i << ' ' << s << ' '  << g << ' ' << dp[i][s][g] << endl;
		if (ss[i] == 's'){
			if (g == 0){
				add(dp[i + 1][s][0], dp[i][s][g]);
				if (s - 1 >= 0) add(dp[i][s - 1][0], dp[i][s][g]);
			} else {
				add(dp[i + 1][s][0], dp[i][s][g]);
			}
		} else {
			if (g == 0){
				add(dp[i + 1][s + 1][1], dp[i][s][g]);
				if (s != 0) add(dp[i][s - 1][0], dp[i][s][g]);
			} else {
				add(dp[i + 1][s + 1][1], dp[i][s][g]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 5002; i++) add(ans, dp[ss.size()][i][0]);
	cout << ans;
}