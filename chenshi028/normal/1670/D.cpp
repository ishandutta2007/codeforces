#include<cstdio>
using namespace std;
int T,n,l,r,md;
inline int calc(int x){
	int a=x/3,b=(x+1)/3,c=(x+2)/3;
	return 2*(a*b+b*c+c*a);
}
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",l))
		for(scanf("%d",&n),l=1,r=5e4;l<r;) if(calc(md=l+r>>1)>=n) r=md;else l=md+1;
	return 0;
}