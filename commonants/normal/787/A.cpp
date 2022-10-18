#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>

using namespace std;

void exgcd(int &x,int &y,int a,int b,int g){
	if(b==0)x=g/a,y=0;
	else{
		exgcd(x,y,b,a%b,g);
		int t=x;x=y,y=t-a/b*x;
	}
}
inline int gcd(int a,int b){
	if(a<b)swap(a,b);
	while(b)b^=a^=b^=a%=b;
	return a;
}
int main(){
	int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
	if(d<b)swap(d,b),swap(a,c);
	if((d-b)%gcd(a,c)==0){
		int x,y;int g=gcd(a,c);
		exgcd(x,y,a,c,d-b);
		int aa=a/g,cc=c/g;
		while(x>=cc&&y<=-aa)x-=cc,y+=aa;
		while(x<0||y>0)x+=cc,y-=aa;
		//printf("%d %d\n",x,y);
		printf("%d\n",x*a+b);
	}else printf("-1\n");
	//while(1);
	return 0;
}