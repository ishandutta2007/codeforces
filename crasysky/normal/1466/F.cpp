#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6,P=1e9+7;
int fa[N],ans[N];
int getfa(int x){ return fa[x]==x?x:fa[x]=getfa(fa[x]); } 
int main(){
	int n,m,k=0; scanf("%d%d",&n,&m);
	rep(i,0,m) fa[i]=i;
	rep(i,1,n){
		int t; scanf("%d",&t);
		int b[3]; b[1]=b[2]=0;
		rep(j,1,t) scanf("%d",&b[j]);
		b[1]=getfa(b[1]),b[2]=getfa(b[2]);
		if (b[1]==b[2]) continue;
		else fa[b[1]]=b[2],ans[++k]=i;
	}
	int s=1; rep(i,1,k) s=2LL*s%P;
	printf("%d %d\n",s,k);
	rep(i,1,k) printf("%d ",ans[i]);
	return 0;
}