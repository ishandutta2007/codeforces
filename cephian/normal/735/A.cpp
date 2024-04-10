#include <algorithm>
#include <iostream>
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

string s;

int main() {
	ios::sync_with_stdio(0); cin.tie();
	int n,k;
	cin >> n >> k >> s;
	int g,t;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'T')
			t = i;
		else if(s[i] == 'G')
			g = i;
	}
	if(g%k != t%k) {
		cout << "NO\n";
		return 0;
	}
	if(t > g) swap(t,g);
	for(int i = t+k; i != g; i += k) {
		if(s[i] == '#') {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}