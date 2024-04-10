#include<cstdio>
#include<algorithm>
#define int long long 
const int N=70;
int x[N],y[N],n,ax,ay,bx,by,t,ans;
inline int Abs(int a){return a<0?-a:a;}
inline int Dis(int i,int j){return Abs(x[i]-x[j])+Abs(y[i]-y[j]);}
inline bool Check(int l,int r){
	for(int i=l;i<=r;i++)
	  if(Dis(l,r)+Dis(i,0)+std::min(Dis(i,r),Dis(i,l))<=t)return 1;
	return 0;
}
signed main(){
	scanf("%lld%lld%lld%lld%lld%lld",&x[1],&y[1],&ax,&ay,&bx,&by);
	for(int i=2;i<N;i++){
	  if((double)x[i-1]*ax+bx<1e17&&(double)x[i-1]*ax+bx<1e17)
		x[i]=x[i-1]*ax+bx,y[i]=y[i-1]*ay+by;
	  else{n=i-1;break;}
	}
	scanf("%lld%lld%lld",x,y,&t);
	for(int i=1,j=1;i<=n;i++){
	  for(;j<=i&&!Check(j,i);++j);
	  ans=std::max(ans,i-j+1);
	}printf("%lld\n",ans);
	return 0;
}