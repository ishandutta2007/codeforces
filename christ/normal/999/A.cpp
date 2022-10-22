#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int a[105];
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	int lst = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d",&a[i]);
		if (a[i] > k) lst = i;
	}
	int st = -1;
	for (int i = n-1; i >= 0; i--) {
		if (a[i] > k) st = i;
	}
	if (st == -1) return !printf ("%d\n",n);
	else printf ("%d\n",n-1-lst+st);
    return 0;
}