#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>

using namespace std;
#define ll long long

const int N = 1005, M = 10;
int n, lens, b[M], c[N], p[N], pp[N], len[N], f[N][N];
char s[N], a[N][N];
int main() {
	// freopen("1.in", "r", stdin);
	scanf("%s%d", s+1, &n), lens=strlen(s+1);
	reverse(s+1, s+lens+1);
	for(int i=1; i<=lens; ++i) s[i]^='0';
	for(int i=1; i<=n; ++i){
		scanf("%s", a[i]+1), len[i]=strlen(a[i]+1);
		reverse(a[i]+1, a[i]+len[i]+1);
		for(int j=1; a[i][j]; ++j) a[i][j]^='0';
		p[i]=i;
	}
	for(int i=0; i<10; ++i) scanf("%d", c+i);
	memset(f, -1, sizeof f), f[0][0]=0;
	for(int i=0; i<lens; ++i){
		int l, r;
		if(s[i+1]==('?'^'0')) l=(i<lens-1?0:1), r=9;
		else l=r=s[i+1];
		for(int x=l; x<=r; ++x){
			int cnt=0, sum=0;
			for(int j=1; j<=n; ++j) cnt+=(a[j][i+1]+x>9), sum+=c[(a[j][i+1]+x)%10];
			for(int j=0; j<=n; ++j){
				if(~f[i][j]) f[i+1][cnt]=max(f[i+1][cnt], f[i][j]+sum);
				int now=p[j+1];
				cnt+=(a[now][i+1]+x==9);
				sum+=-c[(a[now][i+1]+x)%10]+c[(a[now][i+1]+x+1)%10];
			}
		}
		memset(b, 0, sizeof b);
		for(int j=1; j<=n; ++j) ++b[(int)a[j][i+1]];
		for(int j=8; ~j; --j) b[j]+=b[j+1];
		for(int j=n; j; --j) pp[b[(int)a[p[j]][i+1]]--]=p[j];
		memcpy(p, pp, sizeof p);
		// for(int j=0; j<10; ++j) printf("[%3d]", f[i][j]);
		// puts("");
	}
	int sum=0, ans=0;
	for(int i=1; i<=n; ++i) for(int j=lens+1; j<=len[i]; ++j) sum+=c[(int)a[i][j]];
	for(int i=0; i<=n; ++i){
		if(~f[lens][i]) ans=max(ans, f[lens][i]+sum);
		int now=p[i+1];
		for(int j=lens+1; j<=len[now]; ++j) sum-=c[(int)a[now][j]];
		++a[now][lens+1];
		for(int j=lens+1; a[now][j]>9; ++j) ++a[now][j+1], a[now][j]-=10;
		for(int j=lens+1; j<=len[now]; ++j) sum+=c[(int)a[now][j]];
		if(a[now][max(lens, len[now])+1]) sum+=c[(int)a[now][max(lens, len[now])+1]];
	}
	return printf("%d", ans), 0;
}