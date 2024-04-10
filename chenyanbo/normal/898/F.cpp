#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e6+5,W=10;
int n;char a[N];
struct Hash
{
int D;
ll sum[N],mi_w[N];
void init()
{
	mi_w[0]=1;
	rep(i,1,n)mi_w[i]=mi_w[i-1]*W%D;
	rep(i,1,n)sum[i]=(sum[i-1]*W+a[i]-'0')%D;
}
ll qiu(int l,int r)
{
	return ( sum[r]-sum[l-1]*mi_w[r-l+1] )%D;
}
bool ok(int l1,int l2)
{
	return (qiu(1,l1)+qiu(l1+1,l1+l2)-qiu(l1+l2+1,n))%D==0;
}
}h[2];

bool ok(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return 1;
	if(a[l]=='0')return 0;
	return 1;
}

void check(int l1,int l2)
{
	if(!ok(1,l1)||!ok(l1+1,l1+l2))return ;
	rep(o,0,1)
	if(!h[o].ok(l1,l2))return ;
	rep(i,1,l1)putchar(a[i]);
	putchar('+');
	rep(i,l1+1,l1+l2)putchar(a[i]);
	putchar('=');
	rep(i,l1+l2+1,n)putchar(a[i]);
	exit(0);
}

int main()
{
	srand((unsigned ll)(new char));
	//freopen("1.in","r",stdin);
	h[0].D=1e9+rand()%10000;
	h[1].D=h[0].D+1+rand()%10000;
	scanf("%s",a+1);
	n=strlen(a+1);
	rep(o,0,1)h[o].init();
	rep(l,(n+2)/3,n)
	if(ok(n-l+1,n))
	{
		rep(l1,l-1,l)check(l1,n-l-l1);
		rep(l2,l-1,l)check(n-l-l2,l2);
	}
}