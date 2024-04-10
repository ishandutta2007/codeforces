#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 200001
#define P 998244353
int ct[N],fac[N],invf[N],C[N],a[N];
I int GetInv(int x){
	int y=P-2,res=1;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
I void Add(int x,const int d){
	for(R i=x;i<N;i+=i&-i){
		C[i]+=d;
	}
}
I int GetSum(int x){
	int res=0;
	for(R i=x;i!=0;i&=i-1){
		res+=C[i];
	}
	return res;
}
int main(){
	fac[0]=1;
	int n,m,x,cur,ans=0;
	scanf("%d%d",&n,&m);
	for(R i=1;i<=n;i++){
		fac[i]=(L)fac[i-1]*i%P;
	}
	invf[n]=GetInv(fac[n]);
	for(R i=n;i!=0;i--){
		invf[i-1]=(L)invf[i]*i%P;
	}
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
		Add(a[i],1);
		ct[a[i]]++;
	}
	cur=fac[n];
	for(R i=1;i!=N;i++){
		cur=(L)cur*invf[ct[i]]%P;
	}
	for(R i=1;i<=m;i++){
		scanf("%d",&x);
		int pre=GetSum(x-1),all=n-i+1;
		if(all==0){
			ans+=cur;
			if(ans>=P){
				ans-=P;
			}
			break;
		}
		all=GetInv(all);
		ans=((L)all*pre%P*cur+ans)%P;
		if(ct[x]==0){
			break;
		}
		cur=(L)cur*all%P*ct[x]%P;
		Add(x,-1);
		ct[x]--;
	}
	printf("%d",ans);
	return 0;
}