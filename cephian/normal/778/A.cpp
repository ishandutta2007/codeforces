#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <random>
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

string s,t;
int P[200005],n;

bool ok(int v) {
	int u = 0;
	for(int i = 0; i < n; ++i) {
		if(P[i] <= v) continue;
		if(s[i] == t[u]) ++u;
		if(u == t.size()) break;
	}
	return u == t.size();
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	n = s.size();
	for(int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		P[k-1] = i;
	}
	int lo = 0, hi = n;
	while(hi-lo > 1) {
		int md = (lo+hi)/2;
		if(ok(md)) lo = md;
		else hi = md;
	}
	cout << lo << "\n";

	return 0;
}