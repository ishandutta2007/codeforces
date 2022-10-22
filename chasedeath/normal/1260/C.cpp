#include<bits/stdc++.h>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }

int main(){
	//freopen("color.in","r",stdin),freopen("color.out","w",stdout);
	rep(kase,1,rd()) {
		int a=rd(),b=rd(),k=rd();
		if(k==1) puts("REBEL");
		else {
			if(a>b) swap(a,b);
			int g=gcd(a,b); a/=g,b/=g;
			puts((b-1+a-1)/a<k?"OBEY":"REBEL");
		}
	}
}