#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main()
{
	IO_OP;

	string s;
	int ans = 0;
	vector<char> t;
	cin >> s;
	for(char c:s) {
		if(t.size() && t.back() == c) {
			t.pop_back();
			ans++;
		}else {
			t.PB(c);
		}
	}
	if(ans&1) cout << "Yes" << endl;
	else cout << "No" << endl;
}