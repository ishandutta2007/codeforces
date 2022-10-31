#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<int,int> m;

int main() {	
	fio;
	int n,x;
	cin >> n >> x;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		++m[a];
	}
	ll a = 0;
	if(x == 0) {
		for(auto p : m) {
			a += 1LL * p.second * (p.second-1) / 2;
		}
	} else {
		for(auto p : m) {
			a += 1LL * p.second * m[p.first ^ x];
		}
		a/=2;
	}
	cout << a << "\n";
}