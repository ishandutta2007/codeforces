#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

const ll N = 360360;
int n;
ll a[20],b[20];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i)
		cin >> b[i];
	ll tot = 0;
	for(int i = 1; i <= N; ++i) {
		bool w = 0;
		for(int j = 0; j < n; ++j) {
			w |= i%a[j] == b[j];
		}
		tot += w;
	}
	cout << fixed << setprecision(15);
	cout << double(tot)/N << "\n";
	return 0;
}