#include <bits/stdc++.h>
#define fo(a,b,c) for (a=b; a<=c; a++)
#define fd(a,b,c) for (a=b; a>=c; a--)
#define abs(x) ((x)>0?(x):-(x))
#define ll long long
//#define file
using namespace std;

int n,i,j,k,l;
ll X1,Y1,X2,Y2,s,s1,s2,X,Y;
bool bz;

ll gcd(ll x,ll y) {int r=x%y; while (r) x=y,y=r,r=x%y; return y;}
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

void swap(ll &a,ll &b) {ll c=a; a=b;b=c;}
void Exit()
{
	printf("NO\n");
	exit(0);
}

int main()
{
	#ifdef file
	freopen("i.in","r",stdin);
	#endif
	
	scanf("%d",&n);
	scanf("%lld%lld",&X1,&Y1);
	scanf("%lld%lld",&X2,&Y2);
	if (!X1 && !X2) Exit();
	if (!Y1 && !Y2) Exit();
	if (!X1 && !Y1) Exit();
	if (!X2 && !Y2) Exit();
	if (!X1) swap(X1,X2),swap(Y1,Y2);
	
	if (!Y1)
	{
		if (!X2)
		X=X1,Y=Y2;
	}
	else
	{
		if (!X2)
		bz=1,swap(X1,Y1),swap(X2,Y2);
	}
	if (!X && !Y)
	{
		s=lcm(abs(X1),abs(X2));
		s1=s/abs(X1);
		s2=s/abs(X2);
		if (X1*s1==X2*s2) Y=Y1*s1-Y2*s2;
		else Y=Y1*s1+Y2*s2;
		X=gcd(abs(X1),abs(X2));
		Y=abs(Y);
	}
	
	if (X*Y!=n) Exit();
	if (bz) swap(X,Y);
	printf("YES\n");
	fo(i,0,X-1)
	{
		fo(j,0,Y-1)
		printf("%d %d\n",i,j);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}