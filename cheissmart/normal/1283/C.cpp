#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 200005;

int a[N], gived[N];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		gived[a[i]] = 1;
	}
	set<int> x, y;
	for(int i=1;i<=n;i++) {
		if(!gived[i])
			x.insert(i);
	}
	for(int i=1;i<=n;i++) {
		if(a[i] == 0) {
			y.insert(i);
		}
	}
	vi v;
	for(int i:y) {
		if(x.count(i)) {
			v.PB(i);
		}
	}
	if(v.size() != 1) {
		for(int i:v) x.erase(i), y.erase(i);
		for(int i:y) {
			a[i] = *x.begin();
			x.erase(x.begin());
		}
		for(int i=0;i<v.size();i++) {
			a[v[i]] = v[(i+1)%v.size()];
		}
	} else {
		int same = v[0];
		int t = *x.begin(), tt = *next(x.begin());
		if(t == same) swap(t, tt);
		a[same] = t;
		y.erase(same), x.erase(t);
		for(int i:y) {
			a[i] = *x.begin();
			x.erase(x.begin());
		}
	}
	for(int i=1;i<=n;i++)
		cout << a[i] << " ";

}