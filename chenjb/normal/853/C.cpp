#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define LL long long
using namespace std;

struct query
{
	int l,d,r,u;
	int id;
}QUERY[200010];

int N,q;

int p[200010];
int sum1[200010],sum2[200010];

LL C2(LL N){return N * (N-1) / 2;}
LL tr[500010];

struct event
{
	int type,id;
	int x,y;
	int d,u;
};
vector<event>e;
bool cmp1(event a,event b){if (a.x==b.x) return a.y<b.y; else return a.x < b.x;}
bool cmp2(event a,event b){if (a.x==b.x) return a.y<b.y; else return a.x > b.x;}
LL answer[200010];


int lb(int x){return x&-x;}
LL getsumofnumber(LL *tr,int x)
{
	long long s=0;
	while(x)
	{
		s+=tr[x];
		x-=lb(x);
	}return s;
}

void add(LL *tr,int x,int y)
{
	while(x<=N)
	{
		tr[x]+=y;
		x+=lb(x);
	}
}

int main()
{
	scanf("%d%d",&N,&q);
	for (int i=1;i<=N;i++)scanf("%d",&p[i]);
	for (int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&QUERY[i].l,&QUERY[i].d,&QUERY[i].r,&QUERY[i].u);
		answer[i] = C2(N);
	}		
	for(int i=1;i<=q;i++)answer[i] -= C2(N-QUERY[i].r);
	for(int i=1;i<=q;i++)answer[i] -= C2(N-QUERY[i].u);
	for(int i=1;i<=q;i++)answer[i] -= C2(QUERY[i].l-1);
	for(int i=1;i<=q;i++)answer[i] -= C2(QUERY[i].d-1);

	e.clear();
	for (int i=1;i<=q;i++)e.push_back((event){1,i,QUERY[i].l,0,QUERY[i].d,QUERY[i].u});

	memset(tr,0,sizeof(tr));
	for (int i=1;i<=N;i++)e.push_back((event){2,0,i,p[i],0,0});

	sort(e.begin(),e.end(),cmp1);
	for (auto t:e)
	if (t.type == 1)
	{
		answer[t.id] += C2(getsumofnumber(tr,N) - getsumofnumber(tr,t.u));
		answer[t.id] += C2(getsumofnumber(tr,t.d-1));
	}
	else add(tr,t.y,1);
	
	//cout<<p[1]<<endl;


	e.clear();
	for (int i=1;i<=q;i++)
	{
		e.push_back((event){1,i,QUERY[i].r,0,QUERY[i].d,QUERY[i].u});
	}

		//cout<<p[1]<<endl;
	memset(tr,0,sizeof(tr));
	for (int i=1;i<=N;i++)
		e.push_back((event){2,0,i,p[i],0,0});
	sort(e.begin(),e.end(),cmp2);
		//cout<<p[1]<<endl;
	for (auto t:e)
	if (t.type == 1)
	{
		answer[t.id] += C2(getsumofnumber(tr,N) - getsumofnumber(tr,t.u));
		answer[t.id] += C2(getsumofnumber(tr,t.d-1));
	}
	else add(tr,t.y,1);

	for (int i=1;i<=q;i++)printf("%lld\n",answer[i]);
}