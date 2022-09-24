#include <cstdio>

using namespace std;

typedef long long LL;

LL n,m,k,g,p,q,l,INF=1e17;

LL Min(LL a,LL b)
{
	return a<b?a:b;
}

LL GCD(LL a,LL b)
{
	if(a==0) return b;
	
	LL d = GCD(b%a,a), t;
	
	if(b%a==0){
		p = -b/a+1, q=1;
		return d;
	}
	
	t = q;
	q = p;
	p = p*(-b/a)+t;
	
	return d;
}

LL J(LL x,LL y)
{
	if(x==y) return x;
	if((y-x)%g != 0) return INF;
	
	LL _p,_q;
	
	_p = p*(y-x)/g;
	_q = -q*(y-x)/g;
	
	_p %= (m/g), _q %= (n/g);
	if(_p<0) _p+=(m/g);
	if(_q<0) _q+=(n/g);
	
	return x+_p*n;
}

int main()
{
	scanf("%I64d %I64d %I64d",&n,&m,&k);
	
	n*=2, m*=2;
	
	g=GCD(n,m);
	
	LL x,y;
	for(;k--;){
		scanf("%I64d %I64d",&x,&y);
		l=Min(Min(J(x,y),J(x,m-y)),Min(J(n-x,y),J(n-x,m-y)));
		printf("%I64d\n",(l==INF)?-1:l);
	}
	
	return 0;
}