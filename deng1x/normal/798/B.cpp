#include<bits/stdc++.h>

const int N = 100;
const int INF = 0x7f7f7f7f;

char s[N][N];
int n, dp[N][N];
std::map <std::string, int> Hash;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	int len = strlen(s[0]);
	std::string str = s[0];
	memset(dp, 0x7f, sizeof(dp));
	for (int i = 0, j = 0; i < len; ++ i){
		if (Hash.count(str)){
			continue;
		}
		Hash[str] = j;
		dp[0][j ++] = i;
		str += str[0];
		str.erase(str.begin());
	}
	for (int i = 1; i < n; ++ i){
		str = s[i];
		for (int j = 0; j < len; ++ j){
			if (Hash.count(str)){
				int x = Hash[str];
				dp[i][x] = std::min(dp[i][x], dp[i - 1][x] + j);
			}
			str += str[0];
			str.erase(str.begin());
		}
	}
	int min = INT_MAX;
	for (int i = 0; i < len; ++ i){
		min = std::min(dp[n - 1][i], min);
	}
	return printf("%d\n", min == INF ? -1 : min), 0;
}