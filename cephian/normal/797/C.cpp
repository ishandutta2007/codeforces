#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string S;
int c = 0;
vi s,t,u;
const int N = 1e5+5;
int mn[N];

void _t() {
	u.push_back(t.back());
	t.pop_back();
}

void _s() {
	t.push_back(s[c++]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> S;
	int n = S.size();
	for(int i = 0; i < S.size(); ++i)
		s.push_back(S[i]);
	mn[n-1] = s[n-1];
	for(int i = n-2; i >= 0; --i)
		mn[i] = min(s[i],mn[i+1]);

	while(u.size() < n) {
		if(c == n || (!t.empty() && mn[c] >= t.back()))
			_t();
		else _s();
	}
	for(int i = 0; i < n; ++i)
		cout << char(u[i]);
	cout << "\n";
	return 0;
}