#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, k, ans, f[N];
int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) f[i]=i;
	for(int i=1; i<=k; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		if(find(x)==find(y)) ++ans; else f[f[x]]=y;
	}
	printf("%d\n", ans);
	return 0;
}