#include<cstdio>
#include<algorithm>
using namespace std;
const int o=5e5+10;
int T,n,p[o],b[o],c[o];long long invs;
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) b[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),invs=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&p[i]),b[i]=0,c[i]=i-2*p[i]+1;
		for(int i=n;i;--i) invs+=query(p[i]),modify(p[i],1);
		sort(c+1,c+n+1);
		printf("%lld ",invs);
		for(int i=1;i<=n;++i) invs-=c[n-i+1],printf("%lld ",invs-i*(i-1ll)/2);
	}
	return 0;
}