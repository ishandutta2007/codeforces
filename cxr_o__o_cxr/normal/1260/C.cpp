#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
int p1,p2,k,d;
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
inline void solve(){
	p1=read();p2=read();k=read();
	if(k==1){puts("REBEL");return;}
	if(p1>p2)p1^=p2^=p1^=p2;
	d=gcd(p1,p2);p1/=d;p2/=d;
	if((p2-2)/p1+1<k)puts("OBEY");
	else puts("REBEL"); 
}
int main(){
//	freopen("color.in","r",stdin);
//	freopen("color.out","w",stdout);
	int T=read();
	while(T--)solve();
	return (0-0);
}