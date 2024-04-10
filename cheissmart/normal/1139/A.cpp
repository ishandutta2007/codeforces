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
	ll n, ans = 0;
	string s;
	cin >> n >> s;
	for(ll i=0;i<n;i++) {
		if((s[i]-'0')%2 == 0) {
			ans += i+1;
		}
	}
	cout << ans << endl;
}