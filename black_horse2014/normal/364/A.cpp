#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <utility>

#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define MN 4005
#define MX 40000
char t[MN];
int s[MN];
long long cnt[MX], n, rlt;

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int a, i, j;
	
	scanf("%d%s", &a, t + 1);
	
	s[0] = 0;
	n = strlen(t + 1);
	for (i = 1; i <= n; i++) s[i] = s[i - 1] + (t[i] - '0');
	for (i = 1; i <= n; i++)
		for (j = i; j <= n; j++) cnt[s[j] - s[i - 1]]++;
	
	if (!a) rlt = cnt[0] * n * (n + 1) - cnt[0] * cnt[0];
	else {
		for (i = 1; i * i < a; i++) {
			if (a % i) continue;
			if (a / i >= MX) continue; 
			rlt += cnt[i] * cnt[a / i];
		}
		rlt *= 2;
		if (i * i == a) rlt += cnt[i] * cnt[i];
	}
	printf("%I64d\n", rlt);
}