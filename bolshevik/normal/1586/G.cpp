#include<cstdio>
#include<algorithm>
using namespace std;
const int o=4e5+10,MOD=1e9+7;
inline void ad(int&a,int b){a+=b-MOD;a+=(a>>31&MOD);}
int n,t,ans,f[o],b[o];pair<int,int> v[o],s[o];
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos;pos-=lowbit(pos)) ad(b[pos],val);}
inline int query(int pos){int res=0;for(;pos<=2*n;pos+=lowbit(pos)) ad(res,b[pos]);return res;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d%d",&v[i].second,&v[i].first);
	scanf("%d",&t);
	for(int i=1,j;i<=t;++i) scanf("%d",&j),s[i]=v[j];
	sort(v+1,v+n+1);sort(s+1,s+t+1);
	for(int i=1;i<=n;++i) modify(v[i].second,f[i]=1+query(v[i].second));
	for(int i=1;i<=2*n;++i) b[i]=0;
	for(int i=n,j=t;i;--i){
		for(;j&&s[j].first>=v[i].first;--j) modify(s[j].second,1);
		if(query(v[i].second)) ad(ans,f[i]),modify(v[i].second,1);
	}
	printf("%d",ans);
	return 0;
}