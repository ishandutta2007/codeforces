#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;



int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int c,v0,v1,a,l;
	cin >> c >> v0 >> v1 >> a >> l;
	int d = 0;
	while(c > 0) {
		int rd = min(v0 + a*d, v1);
		++d;

		if(d != 1) {
			rd -= l;
		}
		c -= rd;
	}
	cout << d << "\n";
}