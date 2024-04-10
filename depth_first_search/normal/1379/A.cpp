#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50
using namespace std;
int n;char s[N+5],t[N+5];
I bool Try(CI x)
{
	RI i;for(i=1;i<=n;++i) t[i]=s[i];t[n+1]=0;
	if(t[x]=='?') t[x]='a';if(t[x+1]=='?') t[x+1]='b';if(t[x+2]=='?') t[x+2]='a';
	if(t[x+3]=='?') t[x+3]='c';if(t[x+4]=='?') t[x+4]='a';if(t[x+5]=='?') t[x+5]='b';
	if(t[x+6]=='?') t[x+6]='a';for(i=1;i<=n;++i) t[i]=='?'&&(t[i]='z');
	RI p=0;for(i=1;i<=n-6;++i) t[i]=='a'&&t[i+1]=='b'&&
		t[i+2]=='a'&&t[i+3]=='c'&&t[i+4]=='a'&&t[i+5]=='b'&&t[i+6]=='a'&&++p;
	return p==1;
}
int main()
{
	RI Tt,i;scanf("%d",&Tt);W(Tt--)
	{
		for(scanf("%d%s",&n,s+1),i=1;i<=n-6;++i) if(Try(i)) {puts("Yes"),puts(t+1);break;}
		i>n-6&&puts("No");
	}return 0;
}