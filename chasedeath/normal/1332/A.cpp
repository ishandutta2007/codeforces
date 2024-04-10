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

const int N=1010,P=998244353;





int main(){
	rep(kase,1,rd()) {
		int a=rd(),b=rd(),c=rd(),d=rd();
		int x=rd()-a+b,y=rd()-c+d,x1=rd(),y1=rd(),x2=rd(),y2=rd();
		if(x1==x2 && (a!=0 || b!=0)) puts("No");
		else if(y1==y2 && (c!=0 || d!=0)) puts("No");
		else puts(x>=x1 && x<=x2 && y>=y1 && y<=y2 ? "Yes":"No");
	}
}