#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string s;
int a[100005]={0},m;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	for(int i = 1; i <= s.size(); ++i) {
		a[i] = a[i-1] + (s[i-1] == s[i]);
	}
	cin >> m;
	while(m--) {
		int l,r;
		cin >> l >> r;
		cout << a[r-1] - a[l-1] << "\n";
	}
	return 0;
}