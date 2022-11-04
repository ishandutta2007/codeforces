#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

int T, a, b, n;

int main() {
	for(scanf("%d", &T); T; T --)	 {
		scanf("%d %d %d", &a, &b, &n);
		if(n % 3 == 0) pp("%d\n", a); else
		if(n % 3 == 1) pp("%d\n", b); else
		pp("%d\n", a ^ b);
	}
}