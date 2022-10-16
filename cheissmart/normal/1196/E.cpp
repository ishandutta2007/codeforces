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
	
	int q;
	cin >> q;
	while(q--) {
		int b, w;
		cin >> b >> w;
		int x = 2, y = 2;
		if(w > b) {
			swap(w, b);
			x++;
		}
		if(b > 3*w + 1) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		if(b == 3*w + 1) {
			cout << x-1 << " " << y << endl;
			b--;
		}
		vector<pi> buf;
		while(w) {
			buf.EB(x, y+1);
			buf.EB(x, y-1);
			cout << x++ << " " << y << endl;
			w--;
			cout << x++ << " " << y << endl;
			b--;
		}
		while(b--) {
			cout << buf.back().F << " " << buf.back().S << endl;
			buf.pop_back();
		}
	}
	
 }