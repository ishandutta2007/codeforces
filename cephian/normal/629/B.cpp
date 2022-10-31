#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

const int N = 400;
int m[N] = {}, f[N] = {};

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		for(int i = a; i <= b; ++i)
			if(s == "M")
				++m[i];
			else ++f[i];
	}
	int ans = 0;
	for(int i = 0; i < N; ++i) {
		ans = max(ans, min(m[i], f[i]));
	}
	cout << 2*ans << '\n';
}