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
#define LL long long
using namespace std;
int n;char s[2*N+5];
namespace SAM
{
	int Nt=1,lst=1;struct node {int Sz,F,L,S[30];}O[N<<1];
	I void Ins(CI x)
	{
		RI p=lst,o=lst=++Nt;O[o].L=O[p].L+1,O[o].Sz=1;
		W(p&&!O[p].S[x]) O[p].S[x]=o,p=O[p].F;if(!p) return (void)(O[o].F=1);
		RI q=O[p].S[x];if(O[q].L==O[p].L+1) return (void)(O[o].F=q);
		RI k=++Nt;(O[k]=O[q]).Sz=0,O[O[q].F=O[o].F=k].L=O[p].L+1;
		W(p&&O[p].S[x]==q) O[p].S[x]=k,p=O[p].F;
	}
	int q[N<<1],ct[N+5];I void Work()
	{
		RI i;for(i=1;i<=Nt;++i) ++ct[O[i].L];for(i=1;i<=n;++i) ct[i]+=ct[i-1];
		for(i=1;i<=Nt;++i) q[ct[O[i].L]--]=i;for(i=Nt;i;--i) O[O[q[i]].F].Sz+=O[q[i]].Sz;
	}
	int ti,vis[N<<1];I void Qry(CI n,char* s)
	{
		RI i,j,x=1;LL t=0;for(++ti,i=j=1;i<=n;s[n+i]=s[i],++i)
		{
			x^1&&O[O[x].F].L==j-i&&(x=O[x].F);
			W((j-i)^n&&O[x].S[s[j]&31]) x=O[x].S[s[j++]&31];if((j-i)^n) continue;
			if(vis[x]==ti) break;vis[x]=ti,t+=O[x].Sz;
		}printf("%lld\n",t);
	}
}
int main()
{
	RI i;for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;++i) SAM::Ins(s[i]&31);SAM::Work();
	RI Tt;scanf("%d",&Tt);W(Tt--) scanf("%s",s+1),n=strlen(s+1),SAM::Qry(n,s);return 0;
}