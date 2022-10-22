#include<cstdio>
#include<iostream>
using namespace std;
const int o=1e5+10;
int T,n,x[o],t[o],ans,L,R;
inline int chk(int md){
	L=-1e9,R=1e9;
	for(int i=1;i<=n;++i) L=max(L,x[i]-(md-t[i])),R=min(R,x[i]+(md-t[i]));
	return L<=R;
}
int main(){
	for(scanf("%d",&T);T--;printf("%.1lf\n",L/2.0)){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&x[i]),x[i]*=2;
		for(int i=1;i<=n;++i) scanf("%d",&t[i]),t[i]*=2;
		for(int l=0,r=4e8,md;l<r;ans=l) if(chk(md=l+r>>1)) r=md;else l=md+1;
		chk(ans);
	}
	return 0;
}