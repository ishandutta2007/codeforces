#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 110000
#define LN 20
#define X 1000000007
#define add(x,y,v) (e[++ee].nxt=lnk[x],e[lnk[x]=ee].to=y,e[ee].val=v)
using namespace std;
int n,m,s,t,ee,lnk[N+5];struct edge {int to,nxt,val;}e[(N<<1)+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define pc(c) (C==E&&(clear(),0),*C++=c)
		#define tn (x<<3)+(x<<1)
		#define D isdigit(c=tc())
		int T;char c,*A,*B,*C,*E,FI[FS],FO[FS],S[FS];
	public:
		I FastIO() {A=B=FI,C=FO,E=FO+FS;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=tn+(c&15),D);}
		Ts I void read(Ty& x,Ar&... y) {read(x),read(y...);}
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
		#undef D
}F;
class ChairmanTree
{
	private:
		#define L l,mid,O[rt].S[0]
		#define R mid+1,r,O[rt].S[1]
		#define PU(x)\
		(\
			O[x].Sz=O[O[x].S[0]].Sz+O[O[x].S[1]].Sz,\
			O[x].H=O[O[x].S[0]].H+O[O[x].S[1]].H\
		)
		int tot,p[N+5];
		class Hash
		{
			private:
				#define ull unsigned long long
				#define RU Reg ull
				#define CU Con ull
				ull x,y;
			public:
				I Hash() {x=y=0;}I Hash(CU a):x(a),y(a){}I Hash(CU a,CU b):x(a),y(b){}
				I Hash operator + (Con Hash& o) Con {return Hash(x+o.x,y+o.y);}
				I Hash operator - (Con Hash& o) Con {return Hash(x-o.x,y-o.y);}
				I Hash operator * (Con Hash& o) Con {return Hash(x*o.x,y*o.y);}
				I bool operator == (Con Hash& o) Con {return x==o.x&&y==o.y;}
				I bool operator != (Con Hash& o) Con {return x^o.x||y^o.y;}
		}seed,pw[N+5];
		struct node {int Sz,S[2];Hash H;}O[N*LN*10];
		I int Chk(CI tl,CI tr,CI l,CI r,CI rt)
		{
			if(!rt||tl<=l&&r<=tr) return O[rt].Sz;RI mid=l+r>>1;
			return (tl<=mid?Chk(tl,tr,L):0)+(tr>mid?Chk(tl,tr,R):0);
		}
		I int Find(CI rt,CI x)
		{
			RI l=x,r=N,t;W(l<r) Chk(x,t=l+r-1>>1,0,N,rt)<=t-x?r=t:l=t+1;
			return r;
		}
		I void Upt0(CI tl,CI tr,CI l,CI r,int& rt)
		{
			if(O[++tot]=O[rt],rt=tot,tl<=l&&r<=tr) return (void)(rt=0);RI mid=l+r>>1;
			tl<=mid&&(Upt0(tl,tr,L),0),tr>mid&&(Upt0(tl,tr,R),0),PU(rt);
		}
		I void Upt1(CI t,CI l,CI r,int& rt)
		{
			if(O[++tot]=O[rt],rt=tot,l==r) return (void)(O[rt].Sz=1,O[rt].H=pw[l]);
			RI mid=l+r>>1;t<=mid?Upt1(t,L):Upt1(t,R),PU(rt);
		}
		I bool le(CI l,CI r,CI rt1,CI rt2)
		{
			if(l==r) return O[rt1].Sz<O[rt2].Sz;RI mid=l+r>>1;
			if(!O[O[rt1].S[1]].Sz&&O[O[rt2].S[1]].Sz) return true;
			if(O[O[rt1].S[1]].Sz&&!O[O[rt2].S[1]].Sz) return false;
			if(O[O[rt1].S[1]].H!=O[O[rt2].S[1]].H) return le(mid+1,r,O[rt1].S[1],O[rt2].S[1]);
			if(!O[O[rt1].S[0]].Sz) return true;if(!O[O[rt2].S[0]].Sz) return false;
			return le(l,mid,O[rt1].S[0],O[rt2].S[0]);
		}
	public:
		int Rt[N+5];
		I ChairmanTree()
		{
			p[0]=1,pw[0]=Hash(1,1),seed=Hash(233333,456789);
			for(RI i=1;i<=N;++i) p[i]=(p[i-1]<<1)%X,pw[i]=pw[i-1]*seed;
		}
		I int Add(CI k,CI x)
		{
			RI t=Find(k,x),w=k;x^t&&(Upt0(x,t-1,0,N,w),0);
			return Upt1(t,0,N,w),w;
		}
		I bool Less(CI k1,CI k2) {return le(0,N,k1,k2);}
		I int GV(CI l,CI r,CI rt)
		{
			if(!rt||l==r) return O[rt].Sz?p[l]:0;RI mid=l+r>>1;
			return (GV(L)+GV(R))%X;
		}
		#undef L
		#undef R
		#undef PU
}C;
int did[N+5];
class Dijkstra
{
	private:
		int vis[N+5],lst[N+5],cnt[N+5],St[N+5];
		class SegmentTree
		{
			private:
				#define P CI l=1,CI r=n,CI rt=1
				#define L l,mid,rt<<1
				#define R mid+1,r,rt<<1|1
				#define mp make_pair
				#define fir first
				#define sec second
				typedef pair<int,int> Pr;Pr V[N<<2];
				I void PU(CI x)
				{
					if(!~V[x<<1].fir) return (void)(V[x]=V[x<<1|1]);
					if(!~V[x<<1|1].fir) return (void)(V[x]=V[x<<1]);
					V[x]=V[C.Less(V[x<<1].fir,V[x<<1|1].fir)?x<<1:x<<1|1];
				}
			public:
				I void Build(P)
				{
					if(l==r) return (void)(V[rt]=mp(-1,l));RI mid=l+r>>1;
					Build(L),Build(R),PU(rt);
				}
				I void Upt(CI x,CI v,P)
				{
					if(l==r) return (void)(V[rt].fir=v);RI mid=l+r>>1;
					x<=mid?Upt(x,v,L):Upt(x,v,R),PU(rt);
				}
				I int Query() {return ~V[1].fir?V[1].sec:-1;}
		}S;
	public:
		I void Solve()
		{
			RI i,k,f,T=0;S.Build(),did[s]=1,S.Upt(s,0);
			W(~(k=S.Query()))
			{
				for(S.Upt(k,-1),i=lnk[k];i;i=e[i].nxt) !vis[e[i].to]&&
				(
					f=C.Add(C.Rt[k],e[i].val),(!did[e[i].to]||C.Less(f,C.Rt[e[i].to]))&&
						(did[e[i].to]=1,lst[e[i].to]=k,C.Rt[e[i].to]=f,S.Upt(e[i].to,C.Rt[e[i].to]),0)
				);
			}
			if(!did[t]) puts("-1"),exit(0);k=t;W(St[++T]=k,k^s) k=lst[k];
			F.write(C.GV(0,N,C.Rt[t]),'\n'),F.write(T,'\n');W(T) F.write(St[T--],' ');
		}
}D;
int main()
{
	RI i,x,y,z;for(F.read(n,m),i=1;i<=m;++i) F.read(x,y,z),add(x,y,z),add(y,x,z);F.read(s,t);
	return D.Solve(),F.clear(),0;
}