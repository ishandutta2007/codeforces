#include<bits/stdc++.h>
#define int long long
int a,b,c,d,e,f,g;
inline bool Check(int a,int b,int c,int d){return(a+d-1)/d>=(c+b-1)/b;}
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g);
	for(int h=0;h<=e;h++)if(Check(a+h*g,b+(e-h)*f,c,d)){puts("YES");goto Brk;}
	puts("NO");
	Brk:;
	}return 0;
}