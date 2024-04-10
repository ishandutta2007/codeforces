#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
#define sqr(a) ((a)*(a))
using namespace std;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int a,b,c,d,e,f;
int main(){
   // judge();
	read(a);read(b);read(c);read(d);read(e);read(f);
	int ans=sqr(a+e+f);
	ans-=sqr(a);ans-=sqr(c);ans-=sqr(e);
	cout<<ans;
    return 0;
}