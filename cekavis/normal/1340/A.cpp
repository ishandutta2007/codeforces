#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int T, n;
bool vis[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n), memset(vis+1, 0, n), vis[n+1]=1;
		bool o=0;
		for(int i=1, x=n, y; i<=n; ++i){
			scanf("%d", &y);
			o|=(y!=x+1 && !vis[x+1]), vis[x=y]=1;
		}
		puts(o?"No":"Yes");
	}
	return 0;
}