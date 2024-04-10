#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, cnt, a[N], b[N];
pair<int,int> ans[N*3];
void solve(int x, int y){
	ans[++cnt]=make_pair(x, y);
	swap(a[x], a[y]), swap(b[a[x]], b[a[y]]);
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), b[a[i]]=i;
	for(int i=n/2; i>1; --i){
		if(b[i]<=n/2) solve(b[i], n);
		else solve(b[i], 1), solve(1, n);
		solve(n, i);
		if(b[n-i+1]<=n/2) solve(b[n-i+1], n), solve(1, n);
		else solve(b[n-i+1], 1);
		solve(b[n-i+1], n-i+1);
	}
	if(a[1]>a[n]) solve(1, n);
	printf("%d\n", cnt);
	for(int i=1; i<=cnt; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}