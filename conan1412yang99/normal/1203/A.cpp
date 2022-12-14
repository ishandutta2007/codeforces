#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[202];
int32_t main() {
	
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		int x, y;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			if(a[i] == 1)x = i;
			if(a[i] == n)y = i;
		}
		vi v, u;
		for(int i=x;i<n;i++)
			v.PB(a[i]);
		for(int i=0;i<x;i++)
			v.PB(a[i]);
		for(int i=y;i<n;i++)
			u.PB(a[i]);
		for(int i=0;i<y;i++)
			u.PB(a[i]);
		bool ok1 = 1, ok2 = 1;
		for(int i=0;i<n;i++)
			if(v[i] != i+1)
				ok1 = 0;
		for(int i=0;i<n;i++)
			if(u[i] != n-i)
				ok2 = 0;
		if(ok1 || ok2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}