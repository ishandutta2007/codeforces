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
	
	int q;
	cin >> q;
	while(q--) {
		string s;
		int n;
		cin >> n >> s;
		if(n == 2 && s[0] >= s[1]) {
			cout << "NO" << endl;
		} else{
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << s[0] << " " << s.substr(1) << endl;
		}
	}
	
}