#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	int sm=0,mx=0;
	int n;
	cin >> n;
	while(n--) {
		int a;
		cin >> a;
		sm+=a;
		mx = max(a,mx);
	}
	cout << -(sm-2*mx-1) << "\n";


	return 0;
}