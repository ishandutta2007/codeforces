#include <bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int m[10004];

bool ok() {
	vi v;
	for(int i=1;i<10004;i++) {
		if(m[i] & 1) {
			return false;
		}
		if(m[i])
			v.PB(i);
	}
	for(int i=0;i<(int)v.size();i++) {
		for(int j=i;j<(int)v.size();j++) {
			int a = v[i] * v[j], ok = 1;
			for(int k=0;k<(int)v.size();k++) {
				if(a % v[k] != 0) {
					ok = 0;
					break;
				}
				if(v[k]*v[k] == a) {
					if(m[v[k]]/2 % 2 != 0) {
						ok = 0;
						break;
					}
				} else {
					// cout << v[k] << " " << a/v[k] << endl;
					// cout << a << endl;
					if(a/v[k] > 10000 || m[v[k]] != m[a/v[k]]) {
						ok = 0;
						break;
					}
				}
			}
			if(ok) return true;
		}
	}
	return false;
}

int32_t main() {
	
	int q;
	cin >> q;
	while(q--) {
		memset(m, 0, sizeof m);
		int n;
		cin >>n;
		for(int i=0;i<4*n;i++) {
			int t;
			cin >> t;
			m[t]++;
		}
		if(ok()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}