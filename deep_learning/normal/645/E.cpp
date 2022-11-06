#include <algorithm>
#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std; 
typedef long long ll; 
ll ans, dp[26]; 
int lst[26], ord[26]; 
void add(int x)
{
	ans = (ans - dp[x] + MOD) % MOD; 
	dp[x] = (dp[x] + ans + 1) % MOD; 
	ans = (ans + dp[x]) % MOD; 
}
bool comp(int a, int b)
{
	return lst[a] < lst[b]; 
}
int main()
{
	// freopen("645E.in", "r", stdin); 
	int n, k; 
	scanf("%d%d", &n, &k); 
	string str;
	cin >> str; 
	for (int i = 0; i < k; i++)
		lst[i] = -1; 
	for (int i = 0; i < str.size(); i++)
	{
		lst[str[i] - 'a'] = i; 
		add(str[i] - 'a'); 
	}
	for (int i = 0; i < k; i++)
		ord[i] = i; 
	sort(ord, ord + k, comp); 
	for (int i = 0; i < n; i++)
		add(ord[i % k]); 
	cout << (ans + 1) % MOD << endl; 
	return 0; 
}