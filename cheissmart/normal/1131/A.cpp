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
	
	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	int ans = (w1+h1)*2 + (w2+h2)*2 + 8;
	ans -= min(w1+2, w2+2)*2;
	cout << ans << endl;
	
}