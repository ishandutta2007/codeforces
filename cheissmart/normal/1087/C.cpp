#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

pi a[3], b[3];

bool cmp(pi p1, pi p2) {
	return p1.S < p2.S;
}

int main()
{
	IO_OP;
	for(int i=0;i<3;i++) {
		cin >> a[i].F >> a[i].S;
		b[i] = a[i];
	}
	sort(a, a+3);
	sort(b, b+3, cmp);
	vector<pi> v;
	for(int i=a[0].F;i<=a[2].F;i++)
		v.PB({i, b[1].S});
	for(int i=0;i<3;i++) {
		if(a[i].S < b[1].S) {
			for(int j=a[i].S;j<=b[1].S;j++)
				v.PB({a[i].F, j});
		}
		if(a[i].S > b[1].S) {
			for(int j=a[i].S;j>=b[1].S;j--)
				v.PB({a[i].F, j});
		}
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end())-v.begin());
	cout << v.size() << endl;
	for(pi p:v)
		cout << p.F << " " << p.S << endl;
}