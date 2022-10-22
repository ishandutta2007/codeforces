#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=4e5+10;

int a,b,c,d,k;

int main(){
	rep(kase,1,rd()) {
		a=rd(),b=rd(),c=rd(),d=rd(),k=rd();
		int x=(a+c-1)/c,y=(b+d-1)/d;
		if(x+y<=k) printf("%d %d\n",x,y);
		else puts("-1");
	}
}