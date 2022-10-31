#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define LL long long 
using namespace std;
 
const int M = 200001;
priority_queue<int> p; 
int n,m,k,ct,f[M];
LL rs[M],T;
struct vv
{
	int t,id;
} a[M];
bool cmp(vv a,vv b){return (a.t==b.t)?a.id<b.id : a.t<b.t;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].t);
		a[i].id=i; f[i]=a[i].t;
	}
	sort(a+1,a+1+n,cmp);
	while(ct<n || p.size())
	{
		int ir;
		if(p.size()) ir=-p.top(), p.pop(), T+=m;
		else T=(LL)a[++ct].t+m,ir=a[ct].id;
		rs[ir]=T;
		while(ct<n && T>=a[ct+1].t)
		{
			++ct;
			if(ir<a[ct].id) p.push(-a[ct].id);
			else T+=m, rs[a[ct].id]=T, ir=a[ct].id;
		}
		
	}
	for(int i=1;i<=n;i++) cout<<rs[i]<<' ';
}