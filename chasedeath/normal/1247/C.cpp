#include<cstdio> 
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
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
inline void cmax(int &a,int b){ ((a<b)&&(a=b)); }
inline void cmin(int &a,int b){ ((a>b)&&(a=b)); }


const int N=1e6+10;

int n,p;


int main(){
	n=rd(),p=rd();
	rep(i,1,30) {
		int t=n-p*i;
		if(t<=0) continue;
		if(t<i) continue;
		int c=0;
		while(t) c++,t&=t-1;
		if(i>=c) return printf("%d\n",i),0;
	}
	puts("-1");
}