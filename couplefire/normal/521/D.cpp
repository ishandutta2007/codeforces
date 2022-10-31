#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k,m;
struct node
{
	int op;
	long double del;
	int id;
};
vector<node>add[maxn];
vector<node>mul;
bool operator < (const node &a,const node &b){return a.del>b.del;}
int stk[maxn],top=0;
bool cmp(const int &a,const int &b)
{
	return mul[a].op<mul[b].op;
}
int a[maxn],now[maxn],nid[maxn];
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),now[i]=a[i];
	for(int i=1;i<=k;i++)
	{
		int op,t,b;
		scanf("%d%d%d",&op,&t,&b);
		if(op==1)
		{
			if(b>now[t])now[t]=b,nid[t]=i;
		}
		if(op==2)add[t].push_back((node){1,b*1.0,i});
		if(op==3)mul.push_back((node){2,b*1.0,i});
	}
	for(int i=1;i<=n;i++)
	{
		if(nid[i])add[i].push_back((node){0,now[i]-a[i]*1.0,nid[i]});
		sort(add[i].begin(),add[i].end());
		double lst=a[i];
		for(int j=0;j<add[i].size();j++)
		{
			mul.push_back((node){add[i][j].op,(add[i][j].del+lst)/lst,add[i][j].id});
			lst=add[i][j].del+lst;
		}
	}
	sort(mul.begin(),mul.end());
	printf("%d\n",min(m,(int)mul.size()));
	for(int i=0;i<min(m,(int)mul.size());i++)stk[++top]=i;
	sort(stk+1,stk+1+top,cmp);
	for(int i=1;i<=top;i++)printf("%d ",mul[stk[i]].id);
}