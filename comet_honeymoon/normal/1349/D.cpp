#include<bits/stdc++.h>
using namespace std;

const int p=998244353,inv2=(p+1)/2,maxN=300005;
int calc(int n){
	int x=1;while(x<n) x<<=1;
	return x;
}
struct Z{
	int x;
	Z(int x0=0):x(x0){}
}; 
int inline check(int x){return x>=p?x-p:x;}
Z operator +(const Z a,const Z b){return check(a.x+b.x);}
Z operator -(const Z a,const Z b){return check(a.x-b.x+p);}
Z operator *(const Z a,const Z b){return 1LL*a.x*b.x%p;}
Z operator -(const Z a){return check(p-a.x);}
Z& operator +=(Z &a,const Z b){return a=a+b;}
Z& operator -=(Z &a,const Z b){return a=a-b;}
Z& operator *=(Z &a,const Z b){return a=a*b;}
Z fac[maxN],ifac[maxN],inv[maxN];
Z qpow(Z a,int k){
    Z ans=1;
    while(k){
        if(k&1) ans*=a;
        a*=a;
        k>>=1;
    }
    return ans;
}
void init(){
    fac[0]=ifac[0]=fac[1]=ifac[1]=inv[1]=1;
    for(int i=2;i<maxN;i++)
    	fac[i]=fac[i-1]*i,
    	inv[i]=(p-p/i)*inv[p%i],
    	ifac[i]=ifac[i-1]*inv[i];
}

int N;
int A[maxN],SA;
Z G[maxN];

int main(){
	init();
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),SA+=A[i];
	G[0]=N-1;
	for(int i=1;i<SA;i++) G[i]=(Z(SA)*(N-1)+G[i-1]*(N-1)*i)*inv[SA-i];
	for(int i=SA-1;i>=0;i--) G[i]+=G[i+1];
	Z ans=0;
	for(int i=1;i<=N;i++) ans+=G[A[i]];ans-=G[0]*(N-1);
	printf("%d\n",ans*inv[N]);
}