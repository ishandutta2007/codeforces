#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 3e5+5;
int a[N], n, m;

bool test(int ans) {
	int prv = 0;
	for(int i = 0; i < n; ++i) {
		int ov = m-a[i]+prv;
		if(ov > ans) {
			if(a[i]+ans >= prv) {
				prv = max(a[i], prv);
			} else return false;
		}
		//cout << prv << endl;
	}
	return true;
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	int lo = -1, hi = m;
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		//cout << "testing " << md << endl;
		if(test(md)) hi = md;
		else lo = md;
	}
	//cout << endl;
	cout << hi << endl;
}