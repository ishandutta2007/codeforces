#include<cstdio>
#include<iostream>
using namespace std;
const int o=10010;
int T,n,a[o],b[o],x[o],y[o],k;bool flg;
int main(){
	for(scanf("%d",&T);T--;k=flg=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) scanf("%d",&b[i]);
		for(int i=1;i<=n;++i) for(int j=1;j<n;++j)
			if(a[j]>a[j+1]||(a[j]==a[j+1]&&b[j]>b[j+1])) swap(a[j],a[j+1]),swap(b[j],b[j+1]),x[++k]=j,y[k]=j+1;
		for(int i=1;i<n;++i) if(b[i]>b[i+1]){printf("-1\n");flg=true;break;}
		if(flg) continue;
		printf("%d\n",k);
		for(int i=1;i<=k;++i) printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}