#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 3e4 + 20;
const int MAX = 30000;
const int TT = 1600;

int n, d, val[MAXN];
int dp[MAXN + TT][TT];

int brute(int l, int pos, int sum = 0){
	if (pos > 30000)
		return	sum;

	if (l == 1)	
		return	max(brute(l + 1, pos + l + 1, sum + val[pos]), brute(l, pos + l, sum + val[pos]));
	return	max(max(brute(l + 1, pos + l + 1, sum + val[pos]), brute(l - 1, pos + l - 1, sum + val[pos])), brute(l, pos + l, sum + val[pos]));
}

int main(){
	cin >> n >> d;
	for (int i = 0; i < n; i++){
		int temp;	cin >> temp;
		val[temp]++;
	}
	if (d > 1500)
		cout << brute(d, d) << "\n";
	else{
		for (int i = MAX; i >= d; i--)
			for (int j = 1; j < TT; j++){
				if (j == 1)
					dp[i][j] = val[i] + max(dp[i + j][j], dp[i + j + 1][j + 1]);
				else
					dp[i][j] = val[i] + max(max(dp[i + j + 1][j + 1], dp[i + j - 1][j - 1]), dp[i + j][j]);
			}
		cout << dp[d][d] << endl;
	}
	return	0;
}