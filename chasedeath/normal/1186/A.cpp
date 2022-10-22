#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(a,b,c) for(int a=b,a##end=c;a<=a##end;++a)
#define drep(a,b,c) for(int a=b,a##end=c;a>=a##end;--a)


char IO;
int rd(){
	int s=0,f=0;
	while(IO=getchar(),IO<'0'||IO>'9')if(IO=='-')f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(IO=getchar(),IO>='0'&&IO<='9');
	return f?-s:s;
}

const int N=101000,K=50;

int main(){
	int a=rd(),b=rd(),c=rd();
	puts(b>=a&&c>=a?"Yes":"No");
}