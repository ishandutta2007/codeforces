#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 105;
int T, n, a[N], b[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i) scanf("%d", b+i);
		sort(a+1, a+n+1), sort(b+1, b+n+1);
		for(int i=1; i<=n; ++i) printf("%d%c", a[i], " \n"[i==n]);
		for(int i=1; i<=n; ++i) printf("%d%c", b[i], " \n"[i==n]);
	}
	return 0;
}