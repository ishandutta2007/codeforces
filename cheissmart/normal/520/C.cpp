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

const int INF = 1e9 + 7, M = 1e9 + 7;

int ct[256];

int main()
{
	IO_OP;
	
	int n, mx = -INF, k = 0;
	string s;
	cin >> n >> s;
	for(char c:s) {
		ct[c]++;
		if(ct[c] > mx) {
			mx = ct[c];
			k = 1;
		} else if(ct[c] == mx) {
			k++;
		}
	}
	ll p = 1;
	for(int i=0;i<n;i++) {
		p *= k;
		p %= M;
	}
	cout << p << endl;
}