#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define F first
#define S second

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while(t--){
		string a, b, r;
		cin >> a >> b;
		map<char, int> f;
		for(char c : b) f[c]++;
		n = a.size();
		for(int i = n - 1; i >= 0; i--) {
			char c = a[i];
			if(f[c] > 0) r += c;
			f[c]--;
		}
		reverse(r.begin(), r.end());
		if(r == b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}