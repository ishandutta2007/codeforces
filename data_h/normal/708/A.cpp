#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 7;

char str[N];

int main() {
	scanf("%s", str);
	int n = strlen(str);
	for (int i = 0; i < n; i++) {
		if (str[i] > 'a') {
			for (int j = i; j < n; j++) {
				if (str[j] > 'a') {
					str[j]--;
				} else {
					break;
				}
			}
			puts(str);
			return 0;
		}
	}
	str[n - 1] = 'z';
	puts(str);
	return 0;
}