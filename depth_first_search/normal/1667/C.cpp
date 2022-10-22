#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 100000
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char FO[FS],OS[FS],*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
	Tp I void writeln(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,qx[N+5],qy[N+5];
int main()
{
	RI i,c=0;scanf("%d",&n);if(n<=2) return puts("1\n1 1"),0;
	if(n==3) return puts("2\n1 1\n1 2"),0;if(n==4) return puts("3\n1 1\n2 3\n3 2\n"),0;
	do {qx[++c]=n,qy[c]=n--;}W(n%3!=1);
	RI x=n/3+1,y=1;for(i=1;i<=n/3*2;i+=2) qy[++c]=i,qx[c]=x,qy[++c]=i+1,qx[c]=y,++x,++y;
	for(writeln(c),i=1;i<=c;++i) write(qx[i]),writeln(qy[i]);return clear(),0;
}