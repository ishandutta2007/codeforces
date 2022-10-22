/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int div_floor(int x,int y){return (x<0)^(y<0)?-(abs(x)+abs(y)-1)/abs(y):x/y;}
int div_ceil(int x,int y){return (x<0)^(y<0)?-abs(x)/abs(y):(x+y-1)/y;}
int exgcd(int a,int b,int &x,int &y){
	if(!b)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	return y-=a/b*x,d;
}
int a1,a2,b1,b2,l,r;
signed main(){
	cin>>a1>>b1>>a2>>b2>>l>>r;
	int x,y,gcd=exgcd(a1,-a2,x,y);
	if((b2-b1)%gcd)return puts("0"),0;
	x*=(b2-b1)/gcd;y*=(b2-b1)/gcd;
	int dx=abs(a2/gcd),dy=abs(a1/gcd);
	((x%=dx)+=dx)%=dx;y=(a1*x-(b2-b1))/a2;
	if(y<0)((y%=dy)+=dy)%=dy,x=(a2*y+(b2-b1))/a1;
	int l0=max(0ll,div_ceil(l-a1*x-b1,a1*dx)),r0=div_floor(r-a1*x-b1,a1*dx);
	cout<<max(0ll,r0-l0+1);
	return 0;
}
/*1
2 0 3 3 5 21
*/
/*2
2 4 3 0 6 17
*/ 
/*3 
2 0 4 2 -39 -37
*/
/*4 
999999999 999999998 1000000000 999999999 1 10000
*/
/*5
51 -1981067352 71 -414801558 -737219217 1160601982
*/