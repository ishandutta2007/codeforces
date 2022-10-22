#include<cstdio>
int main(){
	int mx,mn,l,n,r;
	int T;scanf("%d",&T);for(;T--;){
	mx=-1,mn=1e9+1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&l,&r),mx=mx>l?mx:l,mn=mn<r?mn:r;
	printf("%d\n",mx-mn>0?mx-mn:0);
	}return 0;
}