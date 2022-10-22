#include<cstdio>
#include<vector>
using namespace std;
const int o=100010;
int n,m;vector<int> vx[o],vy[o];long long a[o],b[o],c[o],ans;
inline int lowbit(int x){return x&-x;}
inline void modify(long long*f,int pos,int val){for(;pos<o;pos+=lowbit(pos)) f[pos]+=val;}
inline long long query(long long*f,int pos){long long res=0;for(;pos;pos-=lowbit(pos)) res+=f[pos];return res;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) for(int j=1,c;j<=m;++j) scanf("%d",&c),vx[c].push_back(i),vy[c].push_back(j);
	for(int i=1,sz;i<o;++i) if(sz=vx[i].size()){
		for(int j=sz,x,y;j--;)
			x=vx[i][j],y=vy[i][j],
			ans+=query(a,o-1)-query(a,y)-(query(c,o-1)-query(c,y))*(x+y)+query(b,y)-query(c,y)*(x-y),
			modify(a,y,x+y),modify(b,y,x-y),modify(c,y,1);
		for(int j=sz,x,y;j--;) x=vx[i][j],y=vy[i][j],modify(a,y,-x-y),modify(b,y,y-x),modify(c,y,-1);
	}
	printf("%lld",ans);
	return 0;
}