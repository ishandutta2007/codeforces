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
	
	int n, v, t = 0, ans = 0;
	cin >> n >> v;
	for(int i=1;i<=n;i++) {
		int b = min(v-t, n-i-t);
		t += b;
		ans += b*i;
		t--;
	}
	cout << ans << endl;
	
}