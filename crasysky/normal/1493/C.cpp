#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int a[N],c[30];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m; static char s[N];
		scanf("%d%d%s",&n,&m,s);
		rep(i,1,n) a[i]=s[i-1]-'a'+1;
		if (n%m){ puts("-1"); continue; }
		rep(j,1,26) c[j]=0; rep(i,1,n) ++c[a[i]];
		bool tg=false; rep(j,1,26) tg=tg||c[j]%m;
		if (!tg){ puts(s); continue; }
		rep(j,1,26) c[j]=0;
		int v=0,p,t;
		rep(i,1,n){//ans[1..i-1]=a[1..i-1] ans[i]>a[i]
			per(j,26,a[i]+1)
				if (v+(c[j]%m==0)<=n/m) p=i,t=j;
			if (c[a[i]]%m==0) ++v; ++c[a[i]];
			if (v>n/m) break;
		}
		rep(j,1,26) c[j]=0;
		rep(i,1,p-1) putchar('a'+a[i]-1),++c[a[i]];
		putchar('a'+t-1),++c[t];
		v=0; rep(j,1,26) v+=(c[j]+m-1)/m;
		rep(i,p+1,n){
			rep(j,1,26)
				if (v+(c[j]%m==0)<=n/m){
					v+=c[j]%m==0,++c[j]; putchar('a'+j-1);
					break;
				}
		}
		putchar('\n');
	}
	return 0;
}