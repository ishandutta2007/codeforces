#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
int gcd(int a, int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int n,k,x,GCD;
signed main(){
	read(n,k);GCD=k;
	for(int i=1;i<=n;i++)read(x),GCD=gcd(GCD,x%k);
	if(GCD){write(k/GCD);putchar('\n');
	for(int i=0;i<k;i+=GCD)write(i),putchar(' ');}
	else{write(1);putchar('\n');write(0);}
}