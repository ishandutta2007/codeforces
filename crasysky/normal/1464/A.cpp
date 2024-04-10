#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int fa[N];
int getfa(int u){  return fa[u]==u?u:fa[u]=getfa(fa[u]); }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m,c=0; scanf("%d%d",&n,&m);
		rep(i,1,n) fa[i]=i;
		rep(i,1,m){
			int x,y; scanf("%d%d",&x,&y);
			if (x==y) --c;
			else{
				if (getfa(x)==getfa(y)) ++c;
				else fa[getfa(x)]=getfa(y);
			}
		}
		printf("%d\n",m+c);
	}
	return 0;
}