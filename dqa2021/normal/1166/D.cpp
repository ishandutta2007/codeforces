#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;  //%I64d
const bool DEBUGMRK=false;

int T;
ll a,b,m;
ll bin[70],lb,rb;
ll ans[70];
void solve(int x)
{
	printf("%d",x);
//	if (rb-b<m)
//	{
////		(*bin)=0;
////		for (int i=x;i>=3;i--) bin[++*bin]=(1<<i-3);
////		bin[++*bin]=1;
//		for (int i=2;i<x;i++) ans[i]=m;
//		ans[x]=m-rb+b;
//		ll tot=a;
//		printf(" %I64d",a);
//		for (int i=2;i<=x;i++)
//		{
//			printf(" %I64d",tot+ans[i]);
//			tot=tot+tot+ans[i];
//		}
//		putchar('\n');
//		return;
//	}
	for (int i=2;i<=x;i++) ans[i]=1;
	ll tot=b-lb;
	(*bin)=1;
	for (int i=x;i>=3;i--) bin[++*bin]=(1LL<<i-3);
	bin[++*bin]=1;
	for (int i=2;i<=x;i++)
	{
		ll tmp=min(tot/bin[i],m-1);
		ans[i]+=tmp;
		tot-=bin[i]*tmp;
	}
	tot=a;
	printf(" %I64d",a);
	for (int i=2;i<=x;i++)
	{
		printf(" %I64d",tot+ans[i]);
		tot=tot+tot+ans[i];
	}
	putchar('\n');
}
int main()
{
	scanf("%d",&T);
	if (DEBUGMRK) printf("%d\n",T);
	while (T--)  //init
	{
		scanf("%I64d%I64d%I64d",&a,&b,&m);
		if (DEBUGMRK) printf("%I64d %I64d %I64d\n",a,b,m);
		if (a==b){printf("1 %I64d\n",a);continue;}
		bool flg=false;
		for (int i=2;i<=50;i++)
		{
			lb=(a+1)*(1LL<<i-2),rb=(a+m)*(1LL<<i-2);
			if (lb>b) break;
			if (b>rb) continue;
//			printf("find %I64d %I64d\n",lb,rb);
			solve(i); flg=true; break;
		}
		if (!flg) puts("-1");
	}
	return 0;
}