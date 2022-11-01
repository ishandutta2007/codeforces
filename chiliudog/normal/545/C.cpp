#include "cstdio"
struct{int x,h,l,r;}t[200000];
int l,m,n,i,j,k;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i) scanf("%d%d",&t[i].x,&t[i].h);
	t[n].x=0x7fffffff;
	m=1;
	for(i=1;i<n;++i){
		if(t[i].x-t[i].h>t[i-1].x){
			++m;
		}else if(t[i].x+t[i].h<t[i+1].x){
			t[i].x+=t[i].h;
			++m;
		}
	}
	printf("%d\n",m);
	return 0;
}