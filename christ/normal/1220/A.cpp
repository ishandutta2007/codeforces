#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5 + 5, MOD = 1e9 + 7;
char s[MN];
int main () {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s);
	assert(strlen(s) == n);
	int cntN = 0;
	for (int i = 0; i < n; i++) cntN += s[i] == 'n';
	n -= cntN * 3;
	for (int i = 0; i < cntN; i++) printf ("1 ");
	for (int i = 0; i < n/4; i++) printf ("0 ");
	printf ("\n");
	return 0;
}