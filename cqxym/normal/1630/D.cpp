#include<stdio.h>
#define R register int
#define L long long
inline int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y); 
}
int a[1000000],minA[500000];
bool tag[500000];
inline L Calc(int x){
	L res=0;
	for(R i=0;i!=x;i++){
		if(tag[i]==true){
			res+=minA[i]; 
		}
	}
	return res<<1;
}
inline void Solve(){
	int n,m,x=0,b;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=m;i++){
		scanf("%d",&b);
		x=Gcd(b,x);
	}
	for(R i=0;i!=x;i++){
		minA[i]=1000000000;
		tag[i]=false;
	}
	b=0;
	L sum=0;
	for(R i=0;i!=n;i++){
		if(a[i]<0){
			a[i]=-a[i];
			tag[b]^=true;
		}
		sum+=a[i];
		if(a[i]<minA[b]){
			minA[b]=a[i];
		}
		b++;
		if(b==x){
			b=0;
		}
	}
	L a1=Calc(x);
	for(R i=0;i!=x;i++){
		tag[i]^=true;
	}
	L a2=Calc(x);
	printf("%lld\n",sum-(a1<a2?a1:a2));
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}