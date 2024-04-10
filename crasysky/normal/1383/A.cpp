#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; char s1[N],s2[N]; int fa[26];
int getfa(int u){ return fa[u]==u?u:fa[u]=getfa(fa[u]); }
int main(){
	int T; scanf("%d",&T);
	while (T--){
	    int n; scanf("%d",&n);
		scanf("%s%s",s1,s2);
		rep(i,1,26) fa[i]=i;
		bool f=false;
		rep(i,0,n-1){
			int c1=s1[i]-'a'+1,c2=s2[i]-'a'+1;
			if (c1>c2) f=true; fa[getfa(c1)]=getfa(c2);
		}
		if (f){ puts("-1"); continue; }
		int s=0; rep(i,1,26) s+=fa[i]!=i;
		printf("%d\n",s);
	}
	return 0;
}