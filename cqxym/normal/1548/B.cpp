#include<stdio.h>
#define R register int
#define L long long
#define I inline
I L Abs(L x){
	return x>0?x:-x;
}
I L Gcd(L x,L y){
	return y==0?x:Gcd(y,x%y);
}
L a[200001],f[200001][18];
I void Solve(){
	int n,ans=0;
	scanf("%d",&n);
	L c,d;
	scanf("%lld",&c);
	for(R i=1;i!=n;i++){
		scanf("%lld",&d);
		a[i]=Abs(c-d);
		c=d;
	}
	for(R i=1;i<=n;i++){
		for(R j=0;j!=18;j++){
			f[i][j]=1;
		}
	}
	for(R i=2;i<=n;i++){
		f[i][0]=a[i-1];
		for(R j=1;j!=18&&1<<j<i;j++){
			f[i][j]=Gcd(f[i-(1<<j-1)][j-1],f[i][j-1]);
		}
	}
	for(R i=2;i<=n;i++){
		int cur=i;
		L g=0;
		for(R j=17;j!=-1;j--){
			if(cur>1<<j&&Gcd(g,f[cur][j])!=1){
				g=Gcd(g,f[cur][j]);
				cur-=1<<j;
			}
		}
		if(i-cur>ans){
			ans=i-cur;
		}
	}
	printf("%d\n",ans+1);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}