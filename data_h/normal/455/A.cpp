#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 111111;

int n;
int a[N], cnt[N];
long long f[N];
vector<pair<int, int> > pairs;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	for(int i = 1; i <= 100000; i++) {
		f[i] = max(f[i - 1], 1LL * cnt[i] * i);
		if (i > 1) {
			f[i] = max(f[i], f[i - 2] + 1LL * cnt[i] * i);
		}
	}
	cout << f[100000] << endl;
	return 0;
}