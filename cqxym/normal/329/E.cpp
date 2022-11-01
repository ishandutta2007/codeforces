#include<stdio.h>
#include<algorithm>
#define R register int
#define N 100001
inline int Min(const int x,const int y){
	return x<y?x:y;
}
inline int Abs(int x,const int y){
	x-=y;
	return x<0?-x:x;
}
int n,px[N],py[N];
int ct[2][2],bx[N],by[N];
int main(){
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d%d",px+i,py+i);
		bx[i]=px[i];
		by[i]=py[i];
	}
	std::sort(bx+1,bx+n+1);
	std::sort(by+1,by+n+1);
	int m=n+1>>1,cx,cy,dx,dy;
	cx=bx[m];
	cy=by[m];
	dx=bx[m+1]-bx[m];
	dy=by[m+1]-by[m];
	bool tag=false;
	if((n&1)==1){
		dx=Min(dx,bx[m]-bx[m-1]);
		dy=Min(dy,by[m]-by[m-1]);
	}
	long long ans=0;
	for(R i=1;i<=n;i++){
		ans+=Abs(cx,px[i])+Abs(cy,py[i]);
		if(px[i]==cx&&py[i]==cy){
			tag=true;
		}
		ct[px[i]<=cx][py[i]<=cy]++;
	}
	if(ct[0][0]!=0&&ct[0][1]!=0&&((n&1)==0||tag==true)){
		ans-=Min(dx,dy);
	}
	printf("%lld",ans<<1);
	return 0;
}