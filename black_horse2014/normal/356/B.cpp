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


#define MX 1000005
#define MN 27
#define rep(i, n) for (int i = 0; i < n; i ++)

using namespace std;

typedef long long LL;

int a, b;
int N, M, d;
int tot[MX][MN];
LL n, m, rlt;

char s[MX], t[MX];

int main() {
	
	cin >> n >> m;
	scanf("%s", s);
	scanf("%s", t);
	
	N = strlen(s); M = strlen(t);
	d = __gcd(N, M);
	
	a = N / d; b = M / d;
	rep(i, N) tot[i % d][s[i] - 'a'] ++;
	
	rep(i, M) {
		rlt += a - tot[i % d][t[i] - 'a'];
	}
	
	m /= a;
	rlt *= m;
	
	cout << rlt << endl;	
	return 0;
}