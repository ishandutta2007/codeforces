#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int T, n;
char s[N], ans[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d%s", &n, s+1);
		for(int x='0'; x<='9'; ++x){
			int a=0, b=x;
			for(int i=1; i<=n; ++i)
				if(s[i]<x)
					if(s[i]<a) goto fail;
					else a=s[i], ans[i]='1';
				else if(s[i]>=b) b=s[i], ans[i]='2';
				else if(s[i]<a) goto fail;
				else a=s[i], ans[i]='1';
			if(a>x) goto fail;
			ans[n+1]=0;
			puts(ans+1);
			goto nxt;
			fail:;
		}
		puts("-");
		nxt:;
	}
	return 0;
}