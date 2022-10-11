#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdio>
using namespace std;
#pragma warning(disable:4996)
long long n, a[100005], s, k;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) { scanf("%lld", &a[i]); s += (a[i] + k - 1) / k; }
	cout << (s + 1) / 2 << endl;
	return 0;
}