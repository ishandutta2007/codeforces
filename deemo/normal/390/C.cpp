#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, q, p[MAXN], f[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> q;
	cin >> s;
	for (int i = 0; i < n; i++)	p[i + 1] = p[i] + int(s[i] == '1');
	for (int i = 0; i < n; i++)	f[i] = int(s[i] == '1') + (i - k < 0?0:f[i - k]);
	while (q--){
		int l, r;	cin >> l >> r, l--, r--;
		int z = l - 1;
		while (~z && z % k != r % k)	z--;
		int cnt = f[r] - (z < 0?0:f[z]);
		int ret = (r - l + 1)/ k - cnt;
		ret += p[r + 1] - p[l] - cnt;
		cout << ret << "\n";
	}
	return 0;
}