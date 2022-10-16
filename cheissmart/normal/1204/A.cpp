#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	string s;
	cin >> s;
	if(s == "0") {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0, ct= 0 ;
	for(char c:s)
		ct += c- '0';
	for(int i=0;i<55;i++) {
		int j = i * 2;
		if(s.size() > j+1)  {
			ans++;
		} else if(s.size() == j+1 && ct != 1) {
			ans++;
		} else {
			break;
		}
	}
	cout << ans << endl;
}