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

const int N=1<<21;


int a,b,c,d,n;





int main(){
	a=rd(),b=rd(),c=rd(),d=rd(),n=rd();
	if(c<d) swap(a,b),swap(c,d);
	int ans=max(0,n-a*(c-1)-b*(d-1));
	ans=min(ans,a+b);
	printf("%d ",ans);
	swap(a,b),swap(c,d);
	ans=min(n/c,a);
	ans+=min((n-ans*c)/d,b);
	printf("%d\n",ans);
}