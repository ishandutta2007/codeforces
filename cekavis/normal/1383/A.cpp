#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int T, n;
char a[N], b[N];
bool vis[20][20];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%s%s", &n, a, b);
		int ans=0;
		memset(vis, 0, sizeof vis);
		for(int i=0; i<n; ++i) if(a[i]>b[i]){
			puts("-1");
			goto skip;
		}
		for(int i=0; i<n; ++i) if(a[i]<b[i]) vis[a[i]-'a'][b[i]-'a']=1;
		for(int i=0; i<20; ++i){
			for(int j=i+1; j<20; ++j) if(vis[i][j]){
				++ans;
				for(int k=j+1; k<20; ++k) vis[j][k]|=vis[i][k];
				break;
			}
		}
		printf("%d\n", ans);
		skip:;
	}
	return 0;
}