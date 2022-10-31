#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int p,f,cnts,cntw,s,w; 
		scanf("%d%d%d%d%d%d",&p,&f,&cnts,&cntw,&s,&w);
		if (s>w) swap(s,w),swap(cnts,cntw);
		int ans=0;
		rep(i,0,min(p/s,cnts)){
			int t=min(cnts-i,f/s);
			ans=max(ans,i+t+min(cntw,(p-i*s)/w+(f-t*s)/w));
		}
		printf("%d\n",ans);
	}
	return 0;
}