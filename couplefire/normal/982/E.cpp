#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
using namespace std;
 
void ex_gcd(long long a,long long b,long long c,long long &x,long long &y){
	if(b==0){
		x=c/a;
		y=0;
		return ;
	}
	ex_gcd(b,a%b,c,x,y);
	swap(x,y); y-=(a/b)*x;
}
 
inline long long gcd(long long x,long long y){
	while(y){
		long long t=y;
		y=x%y;
		x=t;
	}
	return x;
}
 
long long n,m,x,y,dx,dy,a,b,d,z,mod,ansx,ansy;
 
void init(){
	cin>>n>>m>>x>>y>>dx>>dy;
	if(dx==0 && dy==0){
		printf("-1\n");
		return ;
	}
	else if(dx==0){
		if(dy==1){
			if(x%n==0){
				printf("%lld %lld\n",x,m);
				return ;
			}
			else{
				printf("-1\n");
				return ;
			}
		}
		else{
			if(x%n==0){
				printf("%lld %d\n",x,0);
				return ;
			}
			else{
				printf("-1\n");
				return ;
			}
		}
	}
	else if(dy==0){
		if(dx==1){
			if(y%m==0){
				printf("%lld %lld\n",n,y);
				return ;
			}
			else{
				printf("-1\n");
				return ;
			}
		}
		else{
			if(y%m==0){
				printf("%d %lld\n",0,y);
				return ;
			}
			else{
				printf("-1\n");
				return ;
			}
		}
	}
	x*=dx,y*=dy;
	d=gcd(n,m);
	if((x-y)%d!=0){
		printf("-1\n");
		return ;
	}
	ex_gcd(n,m,x-y,a,b);
	mod=n*m/d;
	a%=(m/d);
	z=a*n-x;
	z=((z%mod)+mod)%mod;
	printf("%lld %lld\n",(x+z+2*n)%(2*n),(y+z+2*m)%(2*m));
}
 
int main(int argc, char** argv) {
	init();
	return 0;
}