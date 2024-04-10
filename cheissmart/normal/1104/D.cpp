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
	string s;
	while(cin >> s) {
		if(s == "start") {
			cout << "? " << 0 << ' ' << 1 << endl;
			char res;
			cin >> res;
			if(res == 'x') {
				cout << "! 1" << endl;
				continue;
			}
			int x = 1;
			while(1) {
				cout << "? " << x << " " << 2*x << endl;
				cin >> res;
				if(res == 'y') {
					x = 2*x;
				} else {
					int l = x+1, r = 2 * x;
					while(l <= r) {
						int m = (l + r) / 2;
						cout << "? " << x << " " << m << endl;
						cin >> res;
						if(res == 'x') {
							r = m-1;
						} else {
							l = m+1;
						}
					}
					cout << "! " << l << endl;
					break;
				}
			}
		} else {
			break;
		}
	}

}