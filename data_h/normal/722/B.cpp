#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

const int N = 111;

int n;
int a[N];
char buffer[10000];

bool is_vowel(char x) {
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y';
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	gets(buffer);
	bool flag = true;
	for (int i = 0; i < n; i++) {
		gets(buffer);
		int cnt = 0;
		for (int j = 0; buffer[j]; j++) {
			if (is_vowel(buffer[j])) {
				cnt++;
			}
		}
		if (cnt != a[i]) flag = false;
	}
	printf(flag ? "Yes" : "No");
	return 0;
}