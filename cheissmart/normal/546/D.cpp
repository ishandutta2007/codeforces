#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7, N = 5e6 + 87;

int f[N], p[N];

int main()
{
	IO_OP;
	for(int i=2;i<N;i++) {
		if(p[i]) continue;
		p[i] = i;
		for(ll j=1LL*i*i;j<N;j+=i)
			p[j] = i;
	}
	for(int i=1;i<N;i++) {
		int j = i;
		while(j != 1) {
			int d = p[j];
			while(j % d == 0) {
				j /= d;
				f[i]++;
			}
		}
	}
	for(int i=1;i<N;i++)
		f[i] += f[i-1];
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << f[a] - f[b] << '\n';
	}
	
}