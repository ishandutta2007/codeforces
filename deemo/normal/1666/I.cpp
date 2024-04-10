#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

#define F first
#define S second

int scan(int r, int c){
	cout << "SCAN " << r << " " << c << endl;
	int t;
	cin >> t;
	return t;
}

bool dig(int r, int c){
	cout << "DIG " << r << " " << c << endl;
	int t;
	cin >> t;
	return t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int a = scan(1, 1);
		int b = scan(1, m);
		int rs = (a + b - 2 * m + 6) / 2;
		int cs = a - rs + 4;

		int e = scan(rs/2, cs/2);
		int f = scan(rs/2, 1);
		int c1 = (f - e) / 2 + 1;
		int c2 = cs - c1;
		int dy = e - (c2 - c1);
		int r2 = (rs + dy) / 2;
		int r1 = rs - r2;
		if(dig(r1, c1)) dig(r2, c2);
		else{
			dig(r1, c2);
			dig(r2, c1);
		}
	}
	return 0;
}