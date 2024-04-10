#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
int rd(){
	int s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,P=998244353;

int n,m;
int a[5][5];



int main(){
	int Max=1;
	while(Max*2<3e5) Max<<=1;
	Max--;
	int k=rd();
	int x=k;
	rep(i,0,17) if((k&(1<<i)) && (i==0 || (~k&(1<<(i-1))))) x+=1<<i;
	printf("%d %d\n",3,3);
	printf("%d %d %d\n",Max,x,x);
	printf("%d %d %d\n",k,x,x);
	printf("%d %d %d\n",k,Max,k);
}