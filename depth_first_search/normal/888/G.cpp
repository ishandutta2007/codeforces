#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
using namespace std;
int n,a[N+5];
class FastIO
{
	private:
		#define FS 100000
		#define tc() (A==B&&(B=(A=FI)+fread(FI,1,FS,stdin),A==B)?EOF:*A++)
		#define D isdigit(c=tc())
		char c,*A,*B,FI[FS];
	public:
		I FastIO() {A=B=FI;}
		Tp I void read(Ty& x) {x=0;W(!D);W(x=(x<<3)+(x<<1)+(c&15),D);}
}F;
class Trie
{
	private:
		#define Nxt(op) S[rt][op],x,d-1
		int rt,Nt,S[30*N+5][2];
		I void Ins(int& rt,CI x,CI d)
		{
			!rt&&(rt=++Nt,S[rt][0]=S[rt][1]=0),~d&&(Ins(Nxt(x>>d&1)),0);
		}
		I int Qry(CI rt,CI x,CI d)
		{
			return ~d?(S[rt][x>>d&1]?Qry(Nxt(x>>d&1)):(Qry(Nxt(x>>d&1^1))|(1<<d))):0;
		}
	public:
		I void Clear() {rt=Nt=1,S[1][0]=S[1][1]=0;}
		I void A(CI x,CI d) {Ins(rt,x,d);}I int Q(CI x,CI d) {return Qry(rt,x,d);}
}T;
long long ans;vector<int> V[35];I void Solve(CI d)
{
	if(!~d) return;RI i,t=1<<30,f=0,g=0,s=V[d].size();T.Clear();
	for(i=0;i^s;++i) (V[d][i]>>d&1)?(f=1):(T.A(V[d][i],d),g=1);
	if(f&&g) {for(i=0;i^s;++i) V[d][i]>>d&1&&(t=min(t,T.Q(V[d][i],d)));ans+=t;}
	if(f&&d) {for(V[d-1].clear(),i=0;i^s;++i) V[d][i]>>d&1&&(V[d-1].push_back(V[d][i]),0);Solve(d-1);}
	if(g&&d) {for(V[d-1].clear(),i=0;i^s;++i) V[d][i]>>d&1||(V[d-1].push_back(V[d][i]),0);Solve(d-1);}
}
int main()
{
	RI i,x,y,z;for(F.read(n),i=1;i<=n;++i) F.read(a[i]);
	for(i=1;i<=n;++i) V[30].push_back(a[i]);return Solve(30),printf("%lld\n",ans),0;
}