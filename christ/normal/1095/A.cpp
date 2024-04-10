#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
char s[MN];
int main() {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	int cur = 1;
	for (int i = 1; i <= n;) {
		putchar(s[i]);
		i += cur++;
	}
	putchar(10);
    return 0;
}