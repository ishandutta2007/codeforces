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


const int N=610;



int a,b;




int main(){
	a=rd(),b=rd();
	rep(i,1,100) rep(j,1,100) {
		int x=i,y=j,tx,ty;
		while(x) tx=x%10,x/=10;
		while(y) ty=y%10,y/=10;
		if(tx==a&&ty==b && i+1==j) return printf("%d %d\n",i,j),0;
	}
	puts("-1");
}