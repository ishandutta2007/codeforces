#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int a[1010];
int ans[2];

int work(){
	printf("? ");
	for(int i = 0; i < n; ++i)
		putchar('0' + a[i]);
	puts("");
	fflush(stdout);
	int sum;
	scanf("%d", &sum);
	return n - sum;
}

void gao(int l, int r, int sum0, int sum1, int otsum0){
	assert(r - l >= 1);
	memset(a, 0, sizeof(a));
	int d = (l + r) >> 1;
	for(int i = d + 1; i <= r; ++i) a[i] = 1;
	int sum = work() - otsum0, lt = d - l + 1, rt = r - d;
	int l0 = (sum0 + sum - rt) >> 1, r0 = sum0 - l0;
	int r1 = (sum1 + sum - lt) >> 1, l1 = sum1 - r1;
	
	if(l0 && l1) gao(l, d, l0, l1, otsum0 + r0);
	else if(r0 && r1) gao(d + 1, r, r0, r1, otsum0 + l0);
	else{
		if(!l0) ans[1] = l + 1, ans[0] = r + 1;
		else ans[0] = l + 1, ans[1] = r + 1;
	}
}

int main(){
	scanf("%d", &n);
	
	ans[0] = ans[1] = -1;
	int sum0 = work();
	int sum1 = n - sum0;
	gao(0, n - 1, sum0, sum1, 0);
	printf("! %d %d", ans[0], ans[1]);
	fflush(stdout);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}