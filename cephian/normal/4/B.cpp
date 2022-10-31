#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int mno=0,mxo=0,s,n;
int mn[32],mx[32];
int a[32];

void rem() {
	for(int i = 0; ;++i) {
		if(a[i] > mn[i]) {
			--a[i];
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		cin >> mn[i] >> mx[i];
		mno += mn[i];
		mxo += mx[i];
		a[i] = mx[i];
	}
	if(s < mno || s > mxo) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	int diff = mxo - s;
	while(diff--) {
		rem();
	}
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}