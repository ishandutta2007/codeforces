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
#define LL long long
using namespace std;
int n,m,ta,tb,a[N+5],b[N+5];vector<int> A[N+5],B[N+5];
I void Gmax(LL& x,Con LL& y) {x<y&&(x=y);}I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
I void exgcd(CI x,CI y,int& a,int& b) {y?(exgcd(y,x%y,b,a),b-=x/y*a):(a=1,b=0);}
I int GetInv(CI x,CI y) {RI a,b;return exgcd(x,y,a,b),(a%y+y)%y;}
set<int> S;I LL Work(CI n,CI m,vector<int> A,vector<int> B)
{
	if(n==1) {if(A.size()) return -1;if(B.size()) return B[0];puts("-1"),exit(0);}
	RI t,Inv=GetInv(m,n);LL s=-1;vector<int>::iterator i;S.clear();
	for(i=A.begin();i!=A.end();++i) S.insert(1LL**i*Inv%n);
	for(i=B.begin();i!=B.end();++i) S.find(t=1LL**i*Inv%n)==S.end()&&(S.insert(t),Gmax(s,*i),0);
	if(S.empty()) {puts("-1");exit(0);}set<int>::iterator x,y;
	for(x=S.begin(),y=++S.begin();y!=S.end();++x,++y) (t=*y-*x-1)&&(Gmax(s,1LL*t*m+1LL**x*m%n),0);
	return y=S.begin(),(t=n-1-*x+*y)&&(Gmax(s,1LL*t*m+1LL**x*m%n),0),s;
}
int main()
{
	RI i;for(scanf("%d%d%d",&n,&m,&ta),i=1;i<=ta;++i) scanf("%d",a+i);
	for(scanf("%d",&tb),i=1;i<=tb;++i) scanf("%d",b+i);
	RI d=gcd(n,m);if(d>ta+tb) return puts("-1"),0;sort(a+1,a+ta+1),sort(b+1,b+tb+1);
	for(i=1;i<=ta;++i) A[a[i]%d].push_back(a[i]/d);for(i=1;i<=tb;++i) B[b[i]%d].push_back(b[i]/d);
	LL ans=0;for(i=0;i^d;++i) Gmax(ans,max(Work(n/d,m/d,A[i],B[i]),Work(m/d,n/d,B[i],A[i]))*d+i);
	return printf("%lld\n",ans),0;
}