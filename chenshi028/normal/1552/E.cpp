#include<cstdio>
#include<algorithm>
using namespace std;
const int o=110;
int n,k,m,c[o*o],lst[o],ansx[o],ansy[o];bool vis[o];
int main(){
	scanf("%d%d",&n,&k);m=n;
	for(int i=1;i<=n*k;++i) scanf("%d",&c[i]);
	for(int l=1;n;--k) for(int i=l,cnt=0;1;++i) if(!vis[c[i]]){
		if(lst[c[i]]>=l){
			ansx[c[i]]=lst[c[i]];ansy[c[i]]=i;vis[c[i]]=1;
			if((++cnt)==(n+k-2)/(k-1)){n-=cnt;l=i+1;break;}
		}
		else lst[c[i]]=i;
	}
	for(int i=1;i<=m;++i) printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}