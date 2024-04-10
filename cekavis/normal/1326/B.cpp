#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int n, a[N], b[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", b+i);
	for(int i=1, x=0; i<=n; ++i) a[i]=b[i]+x, x=max(x, a[i]);
	for(int i=1; i<=n; ++i) printf("%d%c", a[i], " \n"[i==n]);
	return 0;
}