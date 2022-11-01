#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 200;
int a[MAXN], n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++) {
			int sum = 0;
			for(int k = 1; k < i; k++)
				sum += a[k];
			for(int k = i; k <= j; k++)
				sum += 1 - a[k];
			for(int k = j + 1; k <= n; k++)
				sum += a[k];
			if (sum > ans)
				ans = sum;
		}
	printf("%d\n", ans);
	return 0;
}