#include <bits/stdc++.h>
using namespace std;

string s[2222];
map<string, int> ms;

int main() {
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) cin>>s[i], ms[s[i]] = 1;
	for (int i = n; i < n + m; i++) {
		cin>>s[i];
		if (ms.count(s[i])) ms[s[i]] += 2;
		else ms[s[i]] = 2;
	}
	int a[5];
	for (int i = 0; i < 4; i++) a[i] = 0;
	for (int i = 0; i < n + m; i++) a[ms[s[i]]]++;
	a[3] /= 2;
	a[1] += (a[3] + 1) / 2;
	a[2] += a[3] / 2;
	if (a[1] > a[2]) puts("YES");
	else puts("NO");
	
	return 0;
}