#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
#define fi first
#define se second
using namespace std;
pair<int,int> a[1000006]; int b[1000006];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; ll w; scanf("%d%lld",&n,&w);
		rep(i,1,n) scanf("%d",&a[i].fi),a[i].se=i,b[i]=0;
		sort(a+1,a+1+n);
		while (a[n].fi>w) --n;
		if (a[n].fi>=(w+1)/2){ printf("1\n%d\n",a[n].se); continue; }
		bool f=false; ll s=0; int c=0;
		rep(i,1,n) if (s+a[i].fi<=w) b[i]=true,s+=a[i].fi,++c;
		if ((w+1)/2<=s){
			printf("%d\n",c);
			rep(i,1,n) if (b[i]) printf("%d ",a[i].se);
			putchar('\n');
		}
		else puts("-1");
	}
    return 0;
}