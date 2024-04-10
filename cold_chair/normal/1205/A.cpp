#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

int n;
int a[100005], b[100005];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	if(n % 2 == 0) {
		pp("NO\n");
		return 0;
	}
	fo(i, 1, n) {
		if(i & 1) a[i] = i * 2 - 1; else a[i] = i * 2;
		if(i & 1) b[i] = a[i] + 1; else b[i] = a[i] - 1;
	}
	pp("YES\n") ;
	fo(i, 1, n) pp("%d ", a[i]);
	fo(i, 1, n) pp("%d ", b[i]);
}