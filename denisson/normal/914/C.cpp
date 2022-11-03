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

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}

string s;
int k;

int dp[1007][1007][2];

int cnt[1111];

int main(){
	//srand(time(NULL));
	//freopen("input.txt", "r", stdin);
	//freopen("output2.txt", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> k;
	if (k == 0) cout << 1, exit(0);
	cnt[1] = 0;
	for (int i = 2; i < 1111; i++){
		cnt[i] = cnt[__builtin_popcount(i)] + 1;
	}

	dp[0][0][0] = 1;
	for (int i = 0; i < s.size(); i++) for (int j = 0; j <= i + 1; j++) for (int f = 0; f < 2; f++) if (dp[i][j][f]){
		int l = 0, r = 1;
		if (f == 0 && s[i] == '0') r = 0;
		for (int c = l; c <= r; c++){
			int newf = f;
			if (f == 0 && s[i] - '0' != c) newf = 1;
			add(dp[i + 1][j + (c == 1)][newf], dp[i][j][f]);
		}
	}	

	int ans = 0;

	for (int i = 1; i < 1111; i++){
		if (cnt[i] == k - 1){
			if (i >= 1007) continue;
			add(ans, dp[s.size()][i][0]);
			add(ans, dp[s.size()][i][1]);
		}
	}
	
	if (k == 1) add(ans, mod - 1);

	cout << ans;
}