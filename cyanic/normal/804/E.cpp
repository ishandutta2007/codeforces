#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define out(a,b) printf("%d %d\n",a,b)

void solve(int x){
	per(i,x,1) out(i,x+1);
	per(i,x,1) out(i,x+2);
	out(x+1,x+3),out(x+2,x+4);
	rep(i,1,x) out(i,x+4);
	rep(i,1,x) out(i,x+3);
	out(x+1,x+4),out(x+2,x+3);
	out(x+1,x+2),out(x+3,x+4);
}

int main(){
    int n; scanf("%d",&n);
	if(n%4==2||n%4==3){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int x=n%4;x<n;x+=4) solve(x);
}