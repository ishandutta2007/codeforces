#include<cstdio>
int map[100001];
int main(){
	int a,b,m,r,ind=0;
	scanf("%d%d%d%d",&a,&b,&m,&r);
	while(map[r]==0){
		map[r]=ind++;
		r=(a*r+b)%m;
	}
	printf("%d\n",ind-map[r]);
	return 0;
}