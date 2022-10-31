#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

//v[i] is longest prefix of s starting from i
vector<int> z_algo(const string &s) {
	int n = s.size(), l = 0, r = 0;
	vector<int> Z(n);
	for(int i = 1; i < n; ++i) {
		if(i <= r && Z[i-l] < r-i+1)
			Z[i] = Z[i-l];
		else {
			l = i, r = max(r,i);
			while(r < n && s[r-l] == s[r]) ++r;
			Z[i] = r---l;
		}
	}
	Z[0] = n;
	return Z;
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> Z = z_algo(s);
	vector<int> num(n+2);
	for(int x : Z) {
		++num[x];
	}
	for(int i = n; i >= 0; --i)
		num[i] += num[i+1];

	int amt = 0;
	for(int l = 1; l <= n; ++l)
		amt += Z[n-l] == l;
	cout << amt << "\n";
	for(int l = 1; l <= n; ++l) {
		if(Z[n-l] == l)
			cout << l << " " << num[l] << "\n";
	}
}