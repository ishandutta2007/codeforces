#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 500000
#define LN 20
using namespace std;
int n,Nt,p[N+5],f[N+5];char s[N+5];
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=Nt,CI rt=1
		#define LT l,mid,rt<<1
		#define RT mid+1,r,rt<<1|1
		int Mx[N<<3];
	public:
		I void U(CI x,CI v,PT)
		{
			if(Mx[rt]=max(Mx[rt],v),l==r) return;RI mid=l+r>>1;x<=mid?U(x,v,LT):U(x,v,RT);
		}
		I int Q(CI L,CI R,PT)
		{
			if(L<=l&&r<=R) return Mx[rt];RI mid=l+r>>1;return max(L<=mid?Q(L,R,LT):0,R>mid?Q(L,R,RT):0);
		}
}T;
class SuffixAutomation
{
	private:
		#define add(x,y) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y)
		int lst;struct node {int L,F[LN+5],S[30];}O[N<<1];
		int d,dI[N<<1],dO[N<<1],ee,lnk[N<<1];struct edge {int to,nxt;}e[N<<1];
		I void dfs(CI x)
		{
			dI[x]=++d;for(RI i=1;i<=LN;++i) O[x].F[i]=O[O[x].F[i-1]].F[i-1];
			for(RI i=lnk[x];i;i=e[i].nxt) dfs(e[i].to);dO[x]=d;
		}
	public:
		I SuffixAutomation() {Nt=lst=1;}I int Ins(CI x)
		{
			RI p=lst,o=lst=++Nt;O[o].L=O[p].L+1;
			W(p&&!O[p].S[x]) O[p].S[x]=o,p=O[p].F[0];if(!p) return O[o].F[0]=1,o;
			RI q=O[p].S[x];if(O[p].L+1==O[q].L) return O[o].F[0]=q,o;
			RI k=++Nt;(O[k]=O[q]).L=O[p].L+1,O[o].F[0]=O[q].F[0]=k;
			W(p&&O[p].S[x]==q) O[p].S[x]=k,p=O[p].F[0];return o;
		}
		I void Init() {for(RI i=1;i<=Nt;++i) add(O[i].F[0],i);dfs(1);}
		I void U(CI x,CI v) {T.U(dI[x],v);}
		I int Q(RI x,CI k)
		{
			RI i;for(i=LN;~i;--i) O[O[x].F[i]].L>=k&&(x=O[x].F[i]);return T.Q(dI[x],dO[x]);
		}
}S;
int main()
{
	RI i;for(scanf("%d%s",&n,s+1),reverse(s+1,s+n+1),i=1;i<=n;++i) p[i]=S.Ins(s[i]&31);S.Init();
	#define Check(i) (max(S.Q(p[i],f[i]-1),S.Q(p[i-1],f[i]-1))>=f[i]-1)
	RI t=1;for(f[1]=1,i=2;i<=n;t=max(t,f[i++]))
		{f[i]=f[i-1]+1;W(f[i]^1&&!Check(i)) --f[i],S.U(p[i-f[i]],f[i-f[i]]);}
	return printf("%d\n",t),0;
}