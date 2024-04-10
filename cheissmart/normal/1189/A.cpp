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

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int n, a[2] = {};
	string s;
	cin >> n >> s;
	for(char c:s)
		a[c - '0']++;
	if(a[0] == a[1]) {
		cout << 2 << endl;
		cout << s[0] << " " << s.substr(1) << endl;
	} else{
		cout << 1 << endl;
		cout << s << endl;
	}
	
}