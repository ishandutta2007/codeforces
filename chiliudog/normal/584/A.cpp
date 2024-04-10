#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=105;
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

int main(){
  //judge();
	int n,t;read(n);read(t);
	if (n==1&&t==10){
		puts("-1");return 0;
	}if (t==10)t=1;
	putchar(t+'0');
	fortodo(i,1,n-1)putchar('0');
    return 0;
}