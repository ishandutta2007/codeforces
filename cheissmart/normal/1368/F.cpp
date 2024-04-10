#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int n;

int R(int k) { // optimal answer
	if(k == 1) return 0;
	int ans = n / k * (k - 1) - (k - 1);
	if(n % k) ans += n % k - 1;
	return ans;
}

signed main()
{
	// IO_OP;
	
	cin >> n;
	vi board(n + 1);
	int mx = -1, k = -1;
	for(int i = 1; i <= n; i++) {
		if(R(i) > mx) {
			mx = R(i);
			k = i;
		}
	}
	vi v;
	for(int i = 0; i < n / k; i++)
		for(int j = 0; j < k - 1; j++)
			v.PB(i * k + j + 1);
	for(int i = n / k * k; i < n - 1; i++)
		v.PB(i + 1);
	int cnt = 0;
	while(cnt < mx) {
		vi my_move;
		for(int i:v)
			if(board[i] == 0) {
				board[i] = 1;
				cnt++;
				my_move.PB(i);
			}
		cout << my_move.size();
		for(int i:my_move) cout << " " << i;
		cout << endl;
		int x;
		cin >> x;
		for(int i = 0; i < my_move.size(); i++) {
			cnt -= board[x];
			board[x] = 0;
			x++;
			if(x > n) x -= n;
		}
	}
	cout << 0 << endl;
	
}