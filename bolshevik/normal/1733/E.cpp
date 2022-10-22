#include<cstdio>
using namespace std;
int q;long long t,x,y,a[240],b[240];
int main(){
	for(scanf("%d",&q);q--;){
		scanf("%lld%lld%lld",&t,&x,&y);
		if(t<x+y){printf("NO\n");continue;}
		for(int i=0;i<240;++i) a[i]=b[i]=0;
		a[0]=t-x-y;b[0]=a[0]+1;
		for(int i=0;i<x+y;++i) for(int j=i;j+1;--j) a[j+1]+=a[j]/2,a[j]-=a[j]/2,b[j+1]+=b[j]/2,b[j]-=b[j]/2;
		if(a[x]^b[x]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}