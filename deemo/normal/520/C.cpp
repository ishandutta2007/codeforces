#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 20;
const int MOD = 1e9 + 7;

int n, cnt[200], cn;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cin >> n >> s;
	for (char ch:s)
		cnt[ch]++;
	sort(cnt, cnt + 200, greater<int>());
	cn = 1;
	for (int i = 1; cnt[i] == cnt[i - 1]; i++)	cn++;
	ll ans = 1;
	for (int i = 0; i < n; i++)
		ans = (ans * cn) % MOD;
	cout << ans << "\n";
	return	0;
}