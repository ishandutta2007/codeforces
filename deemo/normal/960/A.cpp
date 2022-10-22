#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int c[200];

void fail(){
	cout << "NO\n";
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	string t = s;
	sort(t.begin(), t.end());
	if (t != s) fail();
	for (char ch:s)
		c[ch]++;
	if (!c['a'] || !c['b'] || (c['c'] != c['a'] && c['c'] != c['b'])) fail();
	cout << "YES\n";
	return 0;
}