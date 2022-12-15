#include<bits/stdc++.h>
#define ll long long
using namespace std;

inline ll read(){
	ll num=0,neg=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')neg=-1;c=getchar();}
	while(isdigit(c)){num=(num<<3)+(num<<1)+c-'0';c=getchar();}
	return num*neg;
}

ll T,x,y,a,b;

int main(){
	T=read();
	while(T--)
	{
		x=read(),y=read();a=read(),b=read();
		if(x>y)swap(x,y);
		ll ans=min((x+y)*a,x*b+(y-x)*a);
		cout<<ans<<endl;
	}return 0;
}