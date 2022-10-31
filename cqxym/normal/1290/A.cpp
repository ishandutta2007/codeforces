#include<stdio.h>
#define R register int
int a[3501];
inline int Min(int a,int b){
	return a<b?a:b;
}
inline int Max(int &x,int y){
	return x>y?x:y;
}
inline void Solve(){
	int n,m,k,x,ans=0,s;
	scanf("%d%d%d",&n,&m,&k);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	k=Min(m-1,k);
	x=m-1-k;
	for(R i=0;i<=k;i++){
		s=2e9;
		for(R j=0;j<=x;j++){
			s=Min(s,Max(a[i+j+1],a[n-k+i-x+j]));
		}
		ans=Max(ans,s);
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