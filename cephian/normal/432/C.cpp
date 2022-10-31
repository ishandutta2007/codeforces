#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

vector<pair<int,int>> v;
const int N = 1e5+5;
int loc[N];
int p[N];


vector<int> primes;
bool prime[N] = {};
int sub[N];

void do_swap(int i, int j) {
	v.emplace_back(i, j);
	swap(loc[p[i]], loc[p[j]]);
	swap(p[i], p[j]);
}

void transfer(int i, int j) {
	if(i == j) return;
	int lo = 0, hi = primes.size();
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		if(primes[md] <= abs(j-i)+1)
			lo = md;
		else hi = md;
	}
	if(j > i) {
		int to = i+primes[lo]-1;
		do_swap(i, to);
		if(j != to)
			transfer(to, j);
	} else {
		int to = i-primes[lo]+1;
		do_swap(to, i);
		if(j != to)
			transfer(to, j);
	}
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	fill(prime, prime+N, true);
	for(int i = 2; i < N; ++i) {
		if(prime[i]) {
			primes.push_back(i);
			for(ll j = 1LL * i * i; j < N; j += i) {
				prime[j] = false;
			}
		}
	}

	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i];
		loc[p[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		transfer(loc[i], i);
	}
	cout << v.size() << endl;
	for(auto p : v) {
		cout << p.first << " " << p.second << endl;
	}
}