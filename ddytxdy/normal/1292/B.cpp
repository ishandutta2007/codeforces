#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=100,inf=1e17,a=1e19;
LL x[N],y[N],ax,ay,bx,by,n,d[N],xs,ys,t,ans;
LL dis(LL x1,LL y1,LL x2,LL y2){return abs(x1-x2)+abs(y1-y2);}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&xs,&ys,&t);
	for(n=1;;n++){
		long double xx=1.0l*x[n-1]*ax+bx,yy=1.0l*y[n-1]*ay+by;
		if(xx>inf||yy>inf){x[n]=y[n]=inf;break;}
		x[n]=x[n-1]*ax+bx;y[n]=y[n-1]*ay+by;
	}
	n--;
	for(int i=0;i<=n;i++){
		LL tt=t-dis(xs,ys,x[i],y[i]),now=1;
		if(tt<0)continue;
		for(int j=i-1;~j;j--){
			tt-=dis(x[j+1],y[j+1],x[j],y[j]);
			if(tt<0)break;now++;
		}
		tt-=dis(x[0],y[0],x[i+1],y[i+1]);
		if(tt>=0){
			now++;
			for(int j=i+2;;j++){
				tt-=dis(x[j-1],y[j-1],x[j],y[j]);
				if(tt<0)break;now++;
			}
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}