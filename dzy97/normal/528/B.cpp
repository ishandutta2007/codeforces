#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define N 400010

int n, f[N], bit[N], bin[N * 2], cnt = 0;

struct node{
	int l, r;
}a[N];

int ask(int x){
	int ret = 0;
	for(;x;x -= x & -x) ret = max(ret, bit[x]);
	return ret;
}

void modify(int x, int d){
	for(;x <= cnt;x += x & -x) bit[x] = max(bit[x], d);
}

int cmp(const node &a, const node &b){
	return a.r < b.r;
}

int main(){
	scanf("%d", &n);
	int x, y;
	for(int i = 1;i <= n;i ++) scanf("%d%d", &x, &y), a[i].l = x - y, a[i].r = x + y;
	for(int i = 1;i <= n;i ++) bin[++ cnt] = a[i].l, bin[++ cnt] = a[i].r;
	sort(bin + 1, bin + cnt + 1);
	cnt = unique(bin + 1, bin + cnt + 1) - bin - 1;
	for(int i = 1;i <= n;i ++){
		a[i].l = lower_bound(bin + 1, bin + cnt + 1, a[i].l) - bin;
		a[i].r = lower_bound(bin + 1, bin + cnt + 1, a[i].r) - bin;
	}
	sort(a + 1, a + n + 1, cmp);
	int ans = 0, j = 0;
	for(int i = 1;i <= cnt;i ++){
		while(j + 1 <= n && a[j + 1].r == i){
			f[a[j + 1].r] = max(f[a[j + 1].r], ask(a[j + 1].l) + 1);
			j ++;
		}
		modify(i, f[i]);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	
	return 0;
}