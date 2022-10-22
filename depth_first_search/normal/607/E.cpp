#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 50000
#define DB long double
#define eps 1e-20
using namespace std;
int n,m;
struct P {DB x,y;I P(Con DB& a=0,Con DB& b=0):x(a),y(b){}}o;
struct S {DB k,b;I S(Con DB& x=0,Con DB& y=0):k(x),b(y){}}s[N+5];
struct Event
{
	int p;DB A;I Event(CI x=0,Con DB& a=0):p(x),A(a){}
	I bool operator < (Con Event& o) Con {return fabs(A-o.A)>eps?A<o.A:p<o.p;}
}g[2*N+5];
int ct,del[N+5];I void Get(Con DB& x)
{
	RI i;DB d,X1,X2;for(ct=0,i=1;i<=n;++i)
	{
		if((d=(s[i].k*s[i].k+1)*x*x-s[i].b*s[i].b)<-eps) continue;
		X1=(-s[i].k*s[i].b+sqrt(d))/(s[i].k*s[i].k+1),X2=(-s[i].k*s[i].b-sqrt(d))/(s[i].k*s[i].k+1);
		del[i]=0,g[++ct]=Event(i,atan2(s[i].k*X1+s[i].b,X1)),g[++ct]=Event(i,atan2(s[i].k*X2+s[i].b,X2));
	}
	for(sort(g+1,g+ct+1),i=ct;i;--i) !del[g[i].p]&&(del[g[i].p]=i);
}
struct TreeArray
{
	int a[2*N+5];I void Cl() {for(RI i=1;i<=ct;++i) a[i]=0;}
	I void U(RI x) {W(x<=ct) ++a[x],x+=x&-x;}I int Q(RI x,RI t=0) {W(x) t+=a[x],x-=x&-x;return t;}
}T;
I bool Check(Con DB& x)
{
	RI i,t=0;for(Get(x),T.Cl(),i=1;i<=ct;++i) if(i^del[g[i].p])
		{if((t+=T.Q(del[g[i].p])-T.Q(i-1))>=m) return true;T.U(del[g[i].p]);}return false;
}
I DB IP_Dis(CI i,CI j) {DB x=(s[j].b-s[i].b)/(s[i].k-s[j].k),y=s[i].k*x+s[i].b;return sqrt(x*x+y*y);}
set<pair<int,int> > G;set<pair<int,int> >::iterator it;I DB Calc(Con DB& x)
{ 
	RI i,c=0;DB t=0;for(Get(x),i=1;i<=ct;++i) if(i^del[g[i].p])
	{
		for(it=G.upper_bound(make_pair(i,0));it!=G.end()&&it->first<del[g[i].p];++it) ++c,t+=IP_Dis(g[i].p,it->second);
		G.insert(make_pair(del[g[i].p],g[i].p));
	}return t+(m-c)*x;
}
int main()
{
	RI i;ios::sync_with_stdio(false),cin>>n>>o.x>>o.y>>m,o.x/=1000,o.y/=1000;
	for(i=1;i<=n;++i) cin>>s[i].k>>s[i].b,s[i].k/=1000,(s[i].b/=1000)+=s[i].k*o.x-o.y;
	RI t=0;for(i=1;i<=n;++i) fabs(s[i].b)<eps&&++t;if(1LL*t*(t-1)/2>=m) return puts("0"),0;
	DB l=0,r=4e9,mid;for(RI i=1;i<=100;++i) Check(mid=(l+r)/2)?r=mid:l=mid;
	return cout<<fixed<<setprecision(8)<<Calc(r)<<endl,0;
}