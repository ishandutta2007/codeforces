#include<stdio.h>
#define R register int
#define I inline
#define N 15001
I int Max(const int x,const int y){
	return x>y?x:y;
}
I int Min(const int x,const int y){
	return x<y?x:y;
}
int a[N],f[2][N],g[2][N],C0[N],C1[N];
I void Init(const int n){
	for(R i=1;i<=n;i++){
		C0[i]=0;
		C1[i]=N;
	}
}
I void Modify(const int t,int x,const int d,const int n){
	if(t==0){
		for(R i=x;i<=n;i+=i&-i){
			C0[i]=Max(C0[i],d);
		}
	}else{
		for(R i=x;i!=0;i&=i-1){
			C1[i]=Min(C1[i],d);
		}
	}
}
I int GetAns(const int t,int x,const int n){
	int res;
	if(t==0){
		res=0;
		for(R i=x;i!=0;i&=i-1){
			res=Max(res,C0[i]);
		}
	}else{
		res=N;
		for(R i=x;i<=n;i+=i&-i){
			res=Min(res,C1[i]);
		}
	}
	return res;
}
I bool DP(const int n,const int x){
	Init(n);
	bool tag=false;
	for(R i=n;i!=0;i--){
		f[0][i]=GetAns(0,a[i]-1,n);
		f[1][i]=GetAns(1,a[i]+1,n);
		if(f[0][i]!=0||f[1][i]!=N){
			tag=true;
		}
		Modify(0,a[i],g[0][i],n);
		Modify(1,a[i],g[1][i],n);
		int t=i+x-2;
		if(t<=n){
			if(g[1][t]!=N){
				Modify(0,g[1][t],a[t],n);
			}
			if(g[0][t]!=0){
				Modify(1,g[0][t],a[t],n);
			}
		}
	}
	for(R j=1;j<=n;j++){
		g[0][j]=f[0][j];
		g[1][j]=f[1][j];
	}
	return tag;
}
I void Solve(){
	int n,ans=1;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		g[0][i]=0;
		g[1][i]=N;
	}
	g[0][n]=g[1][n]=a[n];
	for(R i=2;i<=n;i++){
		if(DP(n,i)==false){
			break;
		}
		ans=i;
	}
	for(R i=1;i<=n;i++){
		g[0][i]=g[1][i]=a[i];
	}
	for(R i=3;i<=n;i++){
		if(DP(n,i)==false){
			break;
		}
		if(i-1>ans){
			ans=i-1;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}