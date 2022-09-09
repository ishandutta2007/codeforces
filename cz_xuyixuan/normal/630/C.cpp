#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long x; cin >> x;
	long long tmp = (1ll << x) - 1;
	cout << tmp * 2 << endl;
	return 0;
}