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
	int v = 0, h = 0;
	cin >> s;
	for(char c:s) {
		if(c == '0') {
			cout << v+1 << " " << 1 << endl;
			v += 2;
			v %= 4;
		} else {
			cout << h+1 << " " << 2 << endl;
			h += 1;
			h %= 4;
		}
	}
}