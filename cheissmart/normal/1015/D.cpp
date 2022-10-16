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
	
	ll n, k, s;
	cin >> n >> k >> s;
	if(k <= s && s <= (n-1)*k) {
		cout << "YES" << endl;
		int t = 1;
		while(k--) {
			int st = min(s-k, n-1);
			if(t+st <= n) t += st;
			else t -= st;
			s -= st;
			cout << t << " ";
		}
	}
	else cout << "NO" << endl;
	
}