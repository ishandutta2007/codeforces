#include<stdio.h>
#define R register int
#define L long long
int c[2002],k[2002],X[2002],Y[2002],p[2002],n,ct0,ct1,ans2[2002][2],cm[2002];
inline int Abs(int x){
	return x<0?-x:x;
}
inline L Dis(int x,int y){
	if(x==0){
		return c[y];
	}
	if(y==0){
		return c[x];
	}
	return 1ll*(k[x]+k[y])*(Abs(X[x]-X[y])+Abs(Y[x]-Y[y]));
}
L ans,dis[2002];
inline void Prim(){
	int s=0;
	L t,mi,pr,pr2;
	for(R i=1;i<=n;i++){
		mi=2e16;
		for(R j=1;j<=n;j++){
			if(dis[j]>0){
				t=Dis(j,s);
				if(t<dis[j]){
					dis[j]=t;
					cm[j]=s;
				}
				if(dis[j]<mi){
					mi=dis[j];
					pr=cm[j];
					pr2=j;
				}
			}
		}
		s=pr2;
		if(s==0||pr==0){
			p[ct0]=pr+s;
			ct0++;
		}else{
			if(X[s]!=X[pr]&&Y[s]!=Y[pr]){
				ans2[ct1][0]=s;
				ans2[ct1][1]=pr;
				ct1++;
			}
		}
		ans+=mi;
		dis[s]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d%d",&X[i],&Y[i]);
		dis[i]=1e16;
	}
	for(R i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(R i=1;i<=n;i++){
		scanf("%d",&k[i]);
	}
	Prim();
	printf("%lld",ans);
	printf("\n%d\n%d",ct0,p[0]);
	for(R i=1;i<ct0;i++){
		printf(" %d",p[i]);
	}
	printf("\n%d",ct1);
	for(R i=0;i<ct1;i++){
		printf("\n%d %d",ans2[i][0],ans2[i][1]);
	}
	return 0;
}