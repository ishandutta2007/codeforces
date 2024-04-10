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

const int N=905,P=1e9+7;

int n,a,b;


int main(){
	a=rd(),b=rd(),n=rd();
	if(a<b) swap(a,b);
	int l=max(0,n-b),r=min(a,n);
	printf("%d\n",r-l+1);
}