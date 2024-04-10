#include <bits/stdc++.h>
using namespace std;

char s[112345] = {};
int n, k;

int main() {
	scanf("%d%d%s", &n, &k, s);
	for(int i = 0; i < n and k; ++i) {
		int ord = s[i] - 'a';
		if(ord < 13) {
			while(s[i] < 'z' and k) s[i]++, k--;
		}
		else {
			while(s[i] > 'a' and k) s[i]--, k--;
		}
	}
	puts(k ? "-1" : s);
	return 0;
}