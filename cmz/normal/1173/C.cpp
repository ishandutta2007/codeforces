#include<bits/stdc++.h>
using namespace std;
const int N=20+2e5;
int a[N*2];
set<int> st;
int cur,n;
bool judge(int x) {
	if (x < n) return 0;
	if (x >= 2 * n) return 1;
	set<int> qq = st;
	int xn = x- n,xns = 0;
	for (int i = 0; i < xn; i++)
		xns = a[n + i], qq.insert(a[n + i]);
	int tar = 0;
	for (int i = 0; xn + i < n; i++) {
		if (qq.find(tar+1) == qq.end()) return 0;
		int v = a[n + xn + i];
		qq.insert(a[n + xn + i]);
		tar++;
	}
	return true;
}
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d",&a[i]);
		st.insert(a[i]);
	}
	cur = 0;
	for (int i=0;i<n;++i){
		int j=n+i;
		scanf("%d",&a[j]);
		if (a[j] == cur + 1)
			cur++; else cur = 0;
	}
	set<int> qq = st;
	int cnt=0;
	int now=n-cur;
	for(int i = 0; i < now; i++) {
		if (qq.find(cur+1) == qq.end())
			break;
		cur++; cnt++;
		qq.insert(a[n+i]);
		if (cur == n)break;
	}
	if (cur == n) {
		printf("%d",cnt);
		return 0;
	}
	int l = 1; int r = n * 3;
	while (l < r) {
		int m = (l+r) >> 1;
		if (judge(m)) r = m;
		else  l = m + 1;
	}
	printf("%d",l);
	return 0;
}