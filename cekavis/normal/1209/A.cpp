#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 105;
int n, ans, a[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	sort(a+1, a+n+1), n=unique(a+1, a+n+1)-a-1;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<i; ++j) if(a[i]%a[j]==0) goto nxt;
		++ans;
		nxt:;
	}
	printf("%d\n", ans);
	return 0;
}