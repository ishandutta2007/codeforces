#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, m, a[N];
int main() {
	scanf("%d%d", &n, &m);
	if(n>m) return puts("0"), 0;
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	int ans=1;
	for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j)
		ans=(ll)ans*abs(a[i]-a[j])%m;
	printf("%d\n", ans);
	return 0;
}