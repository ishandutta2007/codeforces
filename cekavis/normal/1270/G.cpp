#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int n, T, a[N], vis[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), a[i]=i-a[i];
		int x=1, y=0;
		while(!vis[x]) vis[x]=++y, x=a[x];
		printf("%d\n%d", y-vis[x]+1, x);
		for(int i=a[x]; i!=x; i=a[i]) printf(" %d", i);
		puts("");
		memset(vis+1, 0, n<<2);
	}
	return 0;
}