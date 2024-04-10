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

map<pi, int> m;
int a[200005], b[200005];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];
	int any = 0;
	for(int i=0;i<n;i++) {
		if(a[i] == 0 && b[i] == 0) {
			any++;
			continue;
		}
		if(a[i] == 0)
			continue;
		if(b[i] == 0) {
			m[{0, 1}]++;
			continue;
		}
		int bb = -b[i], aa = a[i];
		if(bb < 0) aa = -aa, bb= -bb;
		int g = __gcd(aa, bb);
		bb /= g, aa /= g;
		m[{bb, aa}]++;
	}
	int mx = 0;
	for(auto p:m) {
		mx = max(mx, p.S);
	}
	cout << mx + any << endl;
}