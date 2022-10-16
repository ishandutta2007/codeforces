#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n, k;
	string s;
	cin >> n >> k >> s;
	int tot = 0;
	for(int i=0;i<n;i++) {
		int v = s[i] - 'a';
		tot += max(v, 25-v);
	}
	if(tot < k) {
		cout << -1 << endl;
		return 0;
	}
	for(int i=0;i<n;i++) {
		int v = s[i] - 'a';
		int d = min(k, max(v, 25-v));
		k -= d;
		if(v > 25-v) {
			s[i] -= d;
		} else {
			s[i] += d;
		}
	}
	cout << s << endl;
	
	
}