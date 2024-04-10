#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T, n;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int ans=0;
		for(int i=1, mx=-1e9, x; i<=n; ++i){
			scanf("%d", &x), mx=max(mx, x);
			ans=max(ans, mx-x);
		}
		if(!ans) puts("0");
		else for(int i=30; ~i; --i) if(ans>>i){ printf("%d\n", i+1); break;}
	}
	return 0;
}