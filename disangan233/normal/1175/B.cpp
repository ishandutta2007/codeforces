#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
stack<ll>s;
ll t,v[100005],f[100005],flag,ans;
inline ll read()
{
	ll zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
inline ll check(ll x) {return (x<(1ll<<32));}
int main()
{
	re t=read();v[0]=1;
	for(re i=1;i<=t;i++)
	{
		char ch[5];scanf("%s",ch);
		if(ch[0]=='f')
		{
			re a=read();
			s.push(i);v[i]=v[i-1]*a,f[i]=f[i-1];
			if(!check(v[i])) f[i]=1,v[i]=0;
		}
		else if(ch[0]=='a')
		{
			v[i]=v[i-1],f[i]=f[i-1];
			if(f[i]) return puts("OVERFLOW!!!"),0;
			ans+=v[i];
			if(!check(ans)) return puts("OVERFLOW!!!"),0;
		}
		else 
		{
			v[i]=v[s.top()-1],f[i]=f[s.top()-1];
			s.pop();
		}
	}
	printf("%I64d\n",ans);
	return 0;
}