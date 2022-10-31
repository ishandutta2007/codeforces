#include<bits/stdc++.h>
#define int long long
#define lxl __int128
//const int N=
using namespace std;

void exgcd(lxl a,lxl b,lxl&x,lxl&y,lxl&g){
	if(b)exgcd(b,a%b,y,x,g),y-=a/b*x;
	else g=a,x=1,y=0;
} 

lxl n,p,a,b,x,y,g;

int read(){
	int x;cin>>x;return x;
}

main(){
	ios::sync_with_stdio(false);
	n=read();
	p=read();
	a=read();
	b=read();
	exgcd(a,b,x,y,g);
	if(p%g)cout<<-1;else{
		x*=p/g,y*=p/g;
//		if(x<0)
		a/=g,b/=g;
		x+=y/a*b,y%=a;
		if(y<0)x-=b,y+=a;
		if(x+y<=n&&x>=0&&y>=0)cout<<(int)x<<' '<<(int)y<<' '<<(int)(n-x-y);
		else cout<<-1;
	}
}