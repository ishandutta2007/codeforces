#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define travel(i,x) for(int i=h[x];i;i=pre[i])

const int N = 200005;
int n, a[N];
char s[N], t[N];
bool vis[N];
inline bool check(int x){
	memset(vis, 0, sizeof vis);
	rep(i, 1, x) vis[a[i]]=1;
	int p=1;
	rep(i, 1, n) if(!vis[i] && s[i]==t[p]) ++p;
	return !t[p];
}
int main() {
	scanf("%s%s", s+1, t+1);
	n=strlen(s+1);
	rep(i, 1, n) scanf("%d", a+i);
	int l=1, r=n, ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) ans=mid, l=mid+1; else r=mid-1;
	}
	return printf("%d", ans), 0;
}