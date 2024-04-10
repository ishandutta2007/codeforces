#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5; int c[30],d[N],pos[N],ans[N]; char s[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		scanf("%s",s); int n=strlen(s);
		rep(i,1,26) c[i]=0;
		rep(i,0,n-1) ++c[s[i]-'a'+1];
		int m; scanf("%d",&m);
		rep(i,1,m) scanf("%d",&d[i]);
		int mx=26;
		while (true){
			int p=0;
			rep(i,1,m) if (!d[i]) pos[++p]=i;
			if (!p) break;
			int t=0;
			per(i,mx,1) if (c[i]>=p){ t=i; break; }
			mx=t-1;
			rep(i,1,m) if (!d[i]) ans[i]=t,d[i]=-1;
			rep(i,1,m)
				rep(j,1,p)
					if (d[i]>0) d[i]-=pos[j]>i?pos[j]-i:i-pos[j];
		}
		rep(i,1,m) putchar(ans[i]+'a'-1); putchar('\n');
	}
	return 0;
}