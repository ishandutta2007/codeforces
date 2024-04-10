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
using namespace std;
int n,a[N+5],res[N+5];
I void U(RI x,CI v) {W(x) a[x]=max(a[x],v),x-=x&-x;}
I int Q(RI x,RI t=0) {W(x<=n) t=max(t,a[x]),x+=x&-x;return t;}
struct S
{
	int p,l,r;I S(CI x=0,CI a=0,CI b=0):p(x),l(a),r(b){}
	I bool operator < (Con S& o) Con {return r>o.r;}
}s[N+5];priority_queue<S> q;
I bool cmp(Con S& x,Con S& y) {return x.l<y.l;}
int main()
{
	RI i,x,y,t=0,w=0;char op;for(scanf("%d",&n),i=1;i<=n;++i) a[i]=1;
	for(i=1;i<=2*n;++i)
	{
		if(cin>>op,op=='+') {++t;continue;}
		if(scanf("%d",&x),(y=Q(x))>t) return puts("NO"),0;s[++w]=S(x,Q(x),t),U(x,t+1);
	}
	for(sort(s+1,s+n+1,cmp),x=i=1;i<=n;++i)
	{
		W(x<=n&&s[x].l==i) q.push(s[x++]);if(q.empty()) return puts("NO");
		if(q.top().r<i) return puts("NO");res[i]=q.top().p,q.pop();
	}
	for(puts("YES"),i=1;i<=n;++i) printf("%d%c",res[i]," \n"[i==n]);return 0;
}