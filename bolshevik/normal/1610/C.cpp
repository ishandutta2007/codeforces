#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,a[o],b[o],ans;
inline bool chk(int md){
	int cnt=0;
	for(int i=1;i<=n;++i) if(md-1-a[i]<=cnt&&cnt<=b[i]) ++cnt;
	return cnt>=md;
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
		for(int l=1,r=ans=n,md;l<r;ans=l) if(chk(md=(l+r>>1)+1)) l=md;else r=md-1;
	}
	return 0;
}