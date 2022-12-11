#include<cstdio>
#define ll long long
#define MN 1000000
#define MOD 666233998244353
#define X 233
char a[MN+5],b[MN+5],v[256];
ll p[MN+5],as,bs;
int main()
{
	int n,i;
	scanf("%d%s%s",&n,a+1,b+1);
	v['N']='S';v['S']='N';v['E']='W';v['W']='E';
	for(p[0]=i=1;i<n;++i)p[i]=p[i-1]*X%MOD;
	for(i=n;--i;)
	{
		as=(as+p[n-i-1]*a[i])%MOD;
		bs=(bs*X+v[b[i]])%MOD;
		if(as==bs)return 0*puts("NO");
	}
	puts("YES");
}