#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define E 200000
#define LN 20
using namespace std;
int n,l;char s[E+5];
class SegmentTree
{
	private:
		#define PT CI l=1,CI r=n
		#define LT S[rt][0],l,mid
		#define RT S[rt][1],mid+1,r
		int Nt,S[N*LN<<2][2];
	public:
		I void U(CI x,CI v,int& rt,PT)
		{
			RI mid=l+r>>1;!rt&&(rt=++Nt),l==r||(x<=mid?U(x,v,LT):U(x,v,RT),0);
		}
		I int Q(CI L,CI R,CI rt,PT)
		{
			RI mid=l+r>>1;return rt&&((L<=l&&r<=R)||(L<=mid&&Q(L,R,LT))||(R>mid&&Q(L,R,RT)));
		}
		I void M(int& x,CI y,PT)
		{
			if(!x||!y) return (void)(x|=y);if(l==r) return;RI mid=l+r>>1;S[++Nt][0]=S[x][0],
			S[Nt][1]=S[x][1],M(S[x=Nt][0],S[y][0],l,mid),M(S[x][1],S[y][1],mid+1,r);
		}
}T;
class SuffixAutomation
{
	private:
		int Nt,lst,t[2*N+5],v[2*N+5];struct node {int Rt,L,F,S[30];}O[2*N+5];
		I bool Q(CI rt,CI p,CI x,CI y)
		{
			if(!rt) return 0;RI t=s[p]&31;if(p<=l&&Q(O[rt].S[t],p+1,x,y)) return 1;
			for(RI i=t+1;i<=26;++i) if(T.Q(x+p-1,y,O[O[rt].S[i]].Rt))
				{for(RI k=1;k^p;++k) putchar(s[k]);putchar(96|i),putchar('\n');return 1;}
			return 0;
		}
	public:
		I SuffixAutomation() {Nt=lst=1;}
		I void Ins(CI id,CI x)
		{
			RI p=lst,o=lst=++Nt;O[o].L=O[p].L+1,T.U(id,1,O[o].Rt);
			W(p&&!O[p].S[x]) O[p].S[x]=o,p=O[p].F;if(!p) return (void)(O[o].F=1);
			RI q=O[p].S[x];if(O[q].L==O[p].L+1) return (void)(O[o].F=q);
			RI k=++Nt;(O[k]=O[q]).L=O[p].L+1,O[o].F=O[q].F=k;
			W(p&&O[p].S[x]==q) O[p].S[x]=k,p=O[p].F;
		}
		I void Work()
		{
			RI i;for(i=1;i<=Nt;++i) ++t[O[i].L];for(i=1;i<=n;++i) t[i]+=t[i-1];
			for(i=Nt;i;--i) v[t[O[i].L]--]=i;for(i=Nt;i^1;--i) T.M(O[O[v[i]].F].Rt,O[v[i]].Rt);
		}
		I void Qry(CI x,CI y) {l>y-x+1&&(l=y-x+1),!Q(1,1,x,y)&&puts("-1");}
}S;
int main()
{
	RI Qt,i;for(scanf("%s",s+1),n=strlen(s+1),i=1;i<=n;++i) S.Ins(i,s[i]&31);S.Work();
	RI x,y;scanf("%d",&Qt);W(Qt--) scanf("%d%d%s",&x,&y,s+1),l=strlen(s+1),S.Qry(x,y);return 0;
}