#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 1000000
using namespace std;
int n,a[N+5],p[N+5],S[N+5][2];char op[N+5];
I void Init(CI x=1)
{
	if(op[x]=='I') return;if(Init(S[x][0]),op[x]=='N') return (void)(a[x]=a[S[x][0]]^1);
	Init(S[x][1]),a[x]=op[x]=='A'?(a[S[x][0]]&a[S[x][1]]):(op[x]=='O'?(a[S[x][0]]|a[S[x][1]]):(a[S[x][0]]^a[S[x][1]]));
}
I void Work(CI x=1)
{
	switch(op[x])
	{
		case 'I':p[x]=1;break;case 'N':Work(S[x][0]);break;
		case 'A':a[S[x][1]]&&(Work(S[x][0]),0),a[S[x][0]]&&(Work(S[x][1]),0);break;
		case 'O':!a[S[x][1]]&&(Work(S[x][0]),0),!a[S[x][0]]&&(Work(S[x][1]),0);break;
		case 'X':Work(S[x][0]),Work(S[x][1]);break;
	}
}
int main()
{
	RI i;char s[5];for(scanf("%d",&n),i=1;i<=n;++i) switch(scanf("%s",s+1),op[i]=s[1])
	{
		case 'A':case 'O':case 'X':scanf("%d%d",S[i],S[i]+1);break;
		case 'N':scanf("%d",S[i]);break;case 'I':scanf("%d",a+i);
	}
	for(Init(),Work(),i=1;i<=n;++i) op[i]=='I'&&putchar(48|(a[1]^p[i]));return 0;
}