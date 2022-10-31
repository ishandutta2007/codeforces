#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;


const int N = 3e5+5;
const int A = 300005;
const int K = 9;
ll can_make[A][K] = {};
int a[N];

int p[N];
bool sqfree[N];
set<int> primes[A];
vector<int> allp;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i = 1; i < N; ++i)
		p[i] = i;
	for(int i = 2; i < A; ++i) {
		if(p[i]) {
			allp.push_back(i);
			for(ll j = 1LL * i; j < A; j += i) {
				primes[j].insert(i);
				p[j] = false;
			}
		}
	}

	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] == 1) {
			cout << 1 << "\n";
			return 0;
		}
		int r = 1;
		for(int x : primes[a[i]])
			r *= x;
		a[i] = r;
		can_make[r][1] = 1;
	}

	for(int a = 1; a < A; ++a) {
		int y = 1;
		for(int x : primes[a])
			y *= x;
		sqfree[a] = y == a;
	}

	for(int k = 2; k < K; ++k) {
		for(int a = A-1; a >= 1; --a) {
			if(!sqfree[a]) continue;
			ll s1 = 0;
			ll s2 = 0;
			for(int x = 1; x*a < A; ++x) {
				if(can_make[a*x][k-1]) ++s1;
				if(can_make[a*x][1]) ++s2;
				if(x > 1)
					can_make[a][k] -= can_make[a*x][k];
			}
			can_make[a][k] += s1*s2;
		}
		if(can_make[1][k]) {
			cout << k << "\n";
			return 0;
		}
	}
	cout << "-1\n";

}