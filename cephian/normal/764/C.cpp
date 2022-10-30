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

const int N = 1e5;
int c[N],n;

vi u,v;
int diff = 0;
map<int,int> b;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	u = vi(n,0),v = vi(n,0);
	for(int i = 1; i < n; ++i)
		cin >> u[i] >> v[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];
	for(int i = 1; i < n; ++i) {
		if(c[u[i]] == c[v[i]]) continue;
		++diff;
		++b[u[i]];
		++b[v[i]];
	}
	if(diff == 0) {
		cout << "YES\n1\n";
		return 0;
	}
	for(auto p : b) {
		if(diff == p.second) {
			cout << "YES\n" << p.first << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}