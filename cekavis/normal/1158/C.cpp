#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 500005;
int T, n, id, a[N], p[N];
bool ok;
void solve(int l, int r){
	if(l>r) return;
	if(a[l]>r+1) ok=0;
	if(a[l]>r || a[l]==-1) p[l]=id--, solve(l+1, r);
	else solve(a[l], r), solve(l, a[l]-1);
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n), id=n, ok=1;
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		solve(1, n);
		if(!ok) puts("-1");
		else for(int i=1; i<=n; ++i) printf("%d%c", p[i], " \n"[i==n]);
	}
	return 0;
}