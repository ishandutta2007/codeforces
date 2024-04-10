#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define LL long long
using namespace std;
LL p,q,s[100000];priority_queue<LL> Q;map<LL,bool> vis;
int main()
{
	RI Tt,i,t;LL k;scanf("%d",&Tt);for(RI T=1;T<=Tt;++T)
	{
		for(t=0,scanf("%lld%lld",&p,&q),i=1;1LL*i*i<=q;++i) !(q%i)&&(s[++t]=i,s[++t]=q/i);
		sort(s+1,s+t+1),Q.push(p);W(!Q.empty())
		{
			if((k=Q.top())%q) {printf("%lld\n",k);break;}Q.pop();
			for(i=2;i<=t;++i) !(k%s[i])&&vis.count(k/s[i])^T&&(Q.push(k/s[i]),vis[k/s[i]]=T);
		}W(!Q.empty()) Q.pop();
	}return 0;
}