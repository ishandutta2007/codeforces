#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long Int;
#define MOD 1000000007LL

Int dp[11];
Int len[11];
Int res, n;
string str;
string query[100008];
int main(){
	cin >> str;
	cin >> n;
	for(int i = 0;i < n;i++)cin >> query[i];
	for(int i = 0;i < 10;i++)dp[i] = i, len[i] = 10;
	for(int i = n - 1;i >= 0;i--){
		Int from = query[i][0] - '0';
		Int val = 0, nl = 1;
		for(int j = query[i].size() - 1;j >= 3;j--){
			int v = query[i][j] - '0';
			val += nl * dp[v];
			nl *= len[v];
			val %= MOD;
			nl %= MOD;
		}
		dp[from] = val;
		len[from] = nl;
	}
	Int b = 1;
	for(int i = str.size() - 1;i >= 0;i--){
		res += b * dp[str[i] - '0'];
		b *= len[str[i] - '0'];
		res %= MOD;
		b %= MOD;
	}
	cout << res << endl;
	return 0;
}