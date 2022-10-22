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
int main () { //ann wins if you can do better
	scanf ("%s",s+1);
	int n = strlen(s+1);
	int mn = 1e9;
	for (int i = 1; i <= n; i++) {
		if (mn < s[i]) printf ("Ann\n");
		else printf ("Mike\n"), mn=s[i];
	}
	return 0;
}