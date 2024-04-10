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
int n;char s[N+5],t[N+5];bitset<N+5> F,G[26];
int main()
{
	RI Qt,i;for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;++i) G[s[i]-'a'].set(i);
	RI op,x,y,l,t1,t2;char c;scanf("%d",&Qt);W(Qt--)
	{
		if(scanf("%d%d",&op,&x),op==1) {cin>>c,G[s[x]-'a'].reset(x),G[(s[x]=c)-'a'].set(x);continue;}
		if(scanf("%d%s",&y,t+1),l=strlen(t+1),y-x+1<l) {puts("0");continue;}
		for(F.set(),i=1;i<=l;++i) F&=G[t[i]-'a']<<l-i;
		t1=(F>>x+l-1).count(),t2=(F>>y+1).count(),printf("%d\n",t1-t2);
	}return 0;
}