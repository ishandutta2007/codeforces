#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
#define ak *
#define lowbit(x) x&-x
#define maxn 200005
#define fr first
#define sc second
int l[100010],r[100010],n;
struct edge
{
	int l,r;
	bool operator<(const edge&a)const
	{
		if(l<a.l) return 1;
		else if(l>a.l) return 0;
		else return r<a.r;
	}
}e[100010];
int main()
{
	int t;cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(register int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]),e[i].l=l[i],e[i].r=r[i];
		sort(e+1,e+n+1); int rr=-1,flag=0;
		for(register int i=1;i<=n;i++)
		{
			if(i==1) {rr=e[i].r;continue;}
			if(e[i].l>rr) {flag=1;break;}
			else rr=max(rr,e[i].r);
		}
		if(!flag) {puts("-1");continue;}
		for(register int i=1;i<=n;i++) puts(r[i]<=rr?"1":"2");
		printf("\n");
	}
}