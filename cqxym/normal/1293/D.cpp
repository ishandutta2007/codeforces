#include<stdio.h>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
struct Node{
	L x,y;
}d[56];
inline L Abs(L x,L y){
	return x<y?y-x:x-y;
}
inline L Dis(Node X,Node Y){
	return Abs(X.x,Y.x)+Abs(X.y,Y.y);
}
int main(){
	int ct,ans=-1;
	Node S;
	L Ax,Ay,Bx,By,t;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&d[0].x,&d[0].y,&Ax,&Ay,&Bx,&By,&S.x,&S.y,&t);
	for(R i=0;d[i].x<=2e16&&d[i].y<=2e16;i++){
		d[i+1].x=d[i].x*Ax+Bx;
		d[i+1].y=d[i].y*Ay+By;
		ct=i;
	}
	for(R i=0;i<=ct;i++){
		for(R j=i+1+ans;j<=ct;j++){
			if(Dis(d[i],d[j])+min(Dis(d[i],S),Dis(d[j],S))<=t){
				ans=j-i;
			}
		}
	}
	printf("%d",ans+1);
	return 0;
}