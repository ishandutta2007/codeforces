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
#define LL long long
using namespace std;
int n,m,a[N+5];LL ans[N+5];queue<int> q;
struct data
{
	int p,v;I data(CI x=0,CI y=0):p(x),v(y){}
	I bool operator < (Con data& o) Con {return v^o.v?v<o.v:p<o.p;}
}s[N+5];priority_queue<int,vector<int>,greater<int> > p;
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
		Tp I void write(Ty x) {W(S[++T]=x%10+48,x/=10);W(T) pc(S[T--]);}
		Tp I void write(Con Ty& x,Con char& y) {write(x),pc(y);}
		I void clear() {fwrite(FO,1,C-FO,stdout),C=FO;}
}F;
class TreeArray
{
	private:
		int v[N+5];
	public:
		I void Add(RI x,CI y) {W(x<=n) v[x]+=y,x+=x&-x;}
		I int Qry(RI x,RI t=0) {W(x) t+=v[x],x-=x&-x;return t;}
}T;
int main()
{
	RI i,f;LL t=0;for(F.read(n),F.read(m),i=1;i<=n;++i) F.read(a[i]),s[i]=data(i,a[i]);
	sort(s+1,s+n+1),i=1;W(i<=n||!p.empty()||!q.empty())
	{
		!(f=q.empty())&&(ans[q.front()]=(t+=m)),i<=n&&p.empty()&&q.empty()&&(t=s[i].v);
		W(!p.empty()&&!T.Qry(p.top())) q.push(p.top()),T.Add(p.top()+1,1),p.pop();
		W(i<=n&&s[i].v<=t) p.push(s[i++].p),!T.Qry(p.top())&&(q.push(p.top()),T.Add(p.top()+1,1),p.pop(),0);
		!f&&(T.Add(q.front()+1,-1),q.pop(),0);
	}
	for(i=1;i<=n;++i) F.write(ans[i]," \n"[i==n]);return F.clear(),0;
}