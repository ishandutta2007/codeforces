#include<iostream>
#include<algorithm>
using namespace std;
long long n, k, a[200009], s, p[200009];
int main() {
	cin >> n >> k;
	for (int i = 0; i < n - k + 1; i++) { p[i]++; p[i + k]--; }
	for (int i = 1; i <= n; i++)p[i] += p[i - 1];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += p[i]*a[i];
	}
	printf("%.15Lf\n", 1.0L*s / (n - k + 1));
	return 0;
}