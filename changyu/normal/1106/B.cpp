#include<cstdio>
#include<algorithm>
#define int long long
struct food{int a,c,p;}a[100001];
inline bool Cmp(food a,food b){return a.c==b.c?a.p<b.p:a.c<b.c;}
int n,m,p[100001],k=1,s;
signed main()
{
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i].a),a[i].p=i;
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i].c);
	std::sort(a+1,a+1+n,Cmp);
	for(int i=1;i<=n;i++)p[a[i].p]=i;
	for(int j,b;m--;){
	  s=0;
	  scanf("%I64d%I64d",&j,&b);j=p[j];
	  if(b>=a[j].a)b-=a[j].a,s+=a[j].a*a[j].c,a[j].a=0;
	  else a[j].a-=b,s+=b*a[j].c,b=0;
	  if(b)for(;k<=n;k++)
		if(b>=a[k].a)b-=a[k].a,s+=a[k].a*a[k].c,a[k].a=0;
		else {a[k].a-=b,s+=b*a[k].c,b=0;break;}
	  printf("%I64d\n",b?0:s);
	}return 0;
}