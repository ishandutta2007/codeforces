#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
#define N 2100010
int A, B, Q;
ll a[N], s[N];

int main(){
	scanf("%d%d%d", &A, &B, &Q);
	for(int i = 1;i <= 2001000;i ++){
		a[i] = A + 1LL * (i - 1) * B;
		s[i] = s[i - 1] + a[i];
	}
	int l, t, m;
	while(Q --){
		scanf("%d%d%d", &l, &t, &m);
		int h = l, r = l + t + 6, mid;
		while(h <= r){
			mid = (h + r) >> 1;
			if(a[mid] <= t && s[mid] - s[l - 1] <= 1LL * t * m) h = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n", (r + 1 == l) ? -1 : r);
	}
	return 0;
}