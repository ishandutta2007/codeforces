#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
mt19937 gen(chrono::steady_clock().now().time_since_epoch().count());
#define ran (uniform_int_distribution<ull>(1,ULLONG_MAX)(gen))
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2504;
int n,m,Q;
ull t[N][N];
map<pair<int,int>,ull>mp;
inline void add(int x,int y,ull v){
	for(;x<=n;x+=x&-x)
		for(int u=y;u<=m;u+=u&-u)t[x][u]+=v;
}
inline ull ask(int x,int y){
	ull ret=0;
	for(;x;x-=x&-x)
		for(int u=y;u;u-=u&-u)ret+=t[x][u];
	return ret;
}
int main(){
	n=read();m=read();Q=read();
	while(Q--){
		static int op,a1,b1,a2,b2;
		static ull x;
		op=read();a1=read();b1=read();a2=read();b2=read();
		switch(op){
			case 1:{
				x=mp[make_pair(a1*3000+b1,a2*3000+b2)]=ran;
				add(a1,b1,x);add(a2+1,b2+1,x);
				add(a1,b2+1,-x);add(a2+1,b1,-x);
				break;
			}
			case 2:{
				x=mp[make_pair(a1*3000+b1,a2*3000+b2)];
				add(a1,b1,-x);add(a2+1,b2+1,-x);
				add(a1,b2+1,x);add(a2+1,b1,x);
				break;
			}
			case 3:{
				if(ask(a1,b1)==ask(a2,b2))puts("Yes");
				else puts("No");
				break;
			}
		}
	}
	return (0-0);
}