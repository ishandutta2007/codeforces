#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
int n,b[233333];
long long x,mx,a[233333];
int nxt(int x){return x<n?x+1:1;}
int pre(int x){return x>1?x-1:n;}
int main(){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,n)mx=mx>b[i]?mx:b[i],x+=b[i];
	if(mx==0){puts("YES");rep(i,1,n)printf("1 ");return 0;}//WA
	int p=1;rep(i,2,n)if(b[i]==mx&&b[i-1]<mx)p=i;
	/*if(mx==x){rep(i,1,n)a[i]=b[i]?mx:2*mx;}//WA
	else for(int i=nxt(p);;i=nxt(i)){
		a[i]=x;x-=b[i];if(i==p)break;
	}*/
	a[p]=mx;mx*=2;for(int i=pre(p);i!=p;i=pre(i)){//WA
		mx+=b[i];a[i]=mx;
	}
	rep(i,1,n)if(b[i]!=a[i]%a[nxt(i)]||a[i]<=0){puts("NO");return 0;}//a[i] in range
	puts("YES");rep(i,1,n)printf("%lld ",a[i]);
	return 0;
}