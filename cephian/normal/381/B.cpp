#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
int a[N];

int md;
vi l,r;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a,a+n);
	l.push_back(a[n-1]);
	r.push_back(a[n-1]);
	for(int i = n-2; i >= 0; --i) {
		if(a[i] != r.back()) {
			r.push_back(a[i]);
			swap(l,r);
		}
	}
	cout << l.size() + r.size()-1 << "\n";
	for(int i = l.size()-1; i > 0; --i) {
		cout << l[i] << " ";
	}
	for(int i = 0; i < r.size(); ++i) {
		cout << r[i] << " ";
	}
	cout << "\n";
	return 0;
}