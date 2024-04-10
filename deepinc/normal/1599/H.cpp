#include<bits/stdc++.h>
using namespace std;
int ask(int a,int b){printf("? %d %d\n",a,b);fflush(stdout);int x; scanf("%d",&x); return x;}
int mx=1e9;
int main(){
	int l=2,r=mx-1,d1=ask(1,1),md,u,d;
	while(l<=r)if(ask(1,md=l+r>>1)+md==d1+1)l=md+1,u=md; else r=md-1;
	l=u;
	u=d1-(l-1)+1;
	d=mx-(ask(mx,1)-(l-1));
	r=mx-(ask(1,mx)-(u-1));
	printf("! %d %d %d %d",u,l,d,r);
}