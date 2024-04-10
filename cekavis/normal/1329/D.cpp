#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005, C = 26;
int T, n, mx, sum, top, a[C], b[N], f[N], g[N], stk[N];
char s[N];
vector<pair<int,int>> ans;
void Dec(int x){
	--sum, --b[a[x]], ++b[--a[x]];
	while(!b[mx]) --mx;
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%s", s+1), n=strlen(s+1);
		for(int i=1; i<=n; ++i) s[i]-='a';
		int x=n;
		for(int i=n; --i;) if(s[i]==s[i+1]){
			f[i]=x-i, x=i;
			--b[a[s[i]]], ++b[++a[s[i]]], mx=max(mx, a[s[i]]), ++sum;
		}
		f[0]=x, g[0]=1;
		// printf(">> %d %d\n", mx, sum);
		for(int i=1; i<n; ++i) if(f[i]){
			if(top && s[stk[top]]!=s[i] && (sum+1)/2>mx){
				Dec(s[i]), Dec(s[stk[top]]);
				ans.emplace_back(g[top], g[top]+f[stk[top]]-1);
				// printf("first: %d %d\n", g[top], g[top]+f[stk[top]]-1);
				--top, f[stk[top]]+=f[i];
			}
			else stk[++top]=i, g[top]=g[top-1]+f[stk[top-1]];
		}
		// for(int i=0; i<=top; ++i) printf("[%d %d %d]\n", stk[i], f[stk[i]], g[i]);
		int y=0, t=top;
		top=0;
		for(int i=0; i<C; ++i) if(a[i]==mx) y=i;
		for(int i=1; i<=t; ++i){
			if(top && (s[stk[top]]==y)!=(s[stk[i]]==y)){
				ans.emplace_back(g[top], g[top]+f[stk[top]]-1);
				// printf("second: %d %d\n", g[top], g[top]+f[stk[top]]-1);
				--top, f[stk[top]]+=f[stk[i]];
			}
			else stk[++top]=stk[i], g[top]=g[top-1]+f[stk[top-1]];
		}
		// for(int i=0; i<=top; ++i) printf("[%d %d %d]\n", stk[i], f[stk[i]], g[i]);
		for(int i=0; i<=top; ++i) ans.emplace_back(1, f[stk[i]]);
		printf("%d\n", (int)ans.size());
		for(auto [i,j]:ans) printf("%d %d\n", i, j);

		for(int i=0; i<=n; ++i) b[i]=a[s[i]]=stk[i]=f[i]=g[i]=0;
		sum=mx=top=0, ans.clear();
	}
	return 0;
}