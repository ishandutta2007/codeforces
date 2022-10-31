#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int a[N], n0[N], np[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	unordered_map<int,int> nxt;
	nxt[0] = -1;
	for(int i = n-1; i >= 0; --i) {
		if(nxt.count(a[i]+1))
			np[i] = nxt[a[i]+1];
		else
			np[i] = -1;
		nxt[a[i]] = i;
		n0[i] = nxt[0];
	}
	int i = 0;
	vector<int> b;
	map<int,int> fn;
	while(i < n) {
		if(n0[i] == -1) {
			b.push_back(0);
			++i;
		} else {
			fn.clear();
			fn[0] = n0[i];
			int p = i-1, mex = 0;
			while(fn.count(mex)) {
				if(fn[mex] <= p) {
					++mex;
				} else {
					++p;
					fn[a[p]] = p;
					if(!fn.count(a[p]+1) && np[p] != -1)
						fn[a[p]+1] = np[p];
				}
			}
			b.push_back(mex);
			i = p+1;
		}
	}
	cout << b.size() << '\n';
	for(int x : b)
		cout << x << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}