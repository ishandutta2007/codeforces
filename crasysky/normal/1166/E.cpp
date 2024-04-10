#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int M=52,N=1e4+4; bitset<M> b[N],b2; int k[M],a[M][N];
int main(){
	int m,n; scanf("%d%d",&m,&n);
	rep(i,1,m){
		scanf("%d",&k[i]);
		rep(j,1,k[i]) scanf("%d",&a[i][j]),b[a[i][j]][i]=1;
	}
	rep(i,1,m){
		b2.reset();
		rep(j,1,k[i]) b2|=b[a[i][j]];
		if (b2.count()!=m){ puts("impossible"); return 0; }
	}
	puts("possible"); return 0;
}