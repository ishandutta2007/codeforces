#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn=300005;
int n;

pair<LL,LL> P[maxn];

struct cmp1
{
	bool operator()(const LL &a,const LL &b)
	{return a>b;}
};

priority_queue<LL> L;
priority_queue<LL,deque<LL>,cmp1> R;
LL cost,can;

int workrank()
{
	LL t;
	while(!R.empty()&&!L.empty()&&R.top()<L.top())
	{
		cost-=L.top();
		cost+=R.top();
		t=L.top();
		L.pop();
		L.push(R.top());
		R.pop();
		R.push(t);
	}
	while(!R.empty()&&cost+R.top()<=can)
	{
		cost+=R.top();
		L.push(R.top());
		R.pop();
	}
	return L.size();
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%I64d%I64d",&P[i].first,&P[i].second),P[i].second=P[i].second-P[i].first+1;
	n--;
	sort(P+1,P+n+1);
	reverse(P+1,P+n+1);
	int orank=1,ans=n+1;
	for(int i=1;i<=n;i++)
		orank+=P[i].first>P[0].first;
	P[n+1].first=0;
	for(int i=orank,j=1;i<=n+1;i++)
	{
		for(;j<=n&&P[j].first>P[i].first;j++)
			R.push(P[j].second);
		can=P[0].first-P[i].first;
		ans=min(ans,i-workrank());
	}
	cout<<ans<<endl;
	return 0;
}