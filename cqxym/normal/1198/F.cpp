#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
struct Num{
	int Id,Num; 
}a[200001];
int g[200001];
int Gcd(int a,int b){
	return b==0?a:Gcd(b,a%b);
}
int main(){
	int i,n,d,r,j=0;
	scanf("%d%d",&n,&d);
	a[0].Num=d;
	for(i=1;i<n;i++){
		scanf("%d",&a[i].Num);
		a[i].Id=i;
		d=Gcd(a[i].Num,d);
	}
	if(d>1){
		printf("NO");
		return 0;
	}
	srand((int)time(0));
	while(j*n<6e6){
		random_shuffle(a,a+n);
		int x=a[0].Num,y=0;
		g[a[0].Id]=1;
		for(i=1;i<n;i++){
			if(a[i].Num%x==0){
				y=Gcd(a[i].Num,y);
				g[a[i].Id]=2;
			}else{
				x=Gcd(a[i].Num,x);
				g[a[i].Id]=1;
			}
		}
		if(x==1&&y==1){
			printf("YES\n");
			for(i=0;i<n;i++){
				printf("%d ",g[i]);
			}
			return 0;
		}
		j++;
	}
	printf("NO");
	return 0;
}