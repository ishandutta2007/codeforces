#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<queue>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
priority_queue<pair<long long,long long>/**/> pq,pq2;
vector<long long> cand,sp;
long long n,m,i,j,t[50005],s[50005],p[50005],now[50005],l,r,mid,ned,x,ans,lst[50005],tt;
set<long long> used;
void get()
{
	while (!pq.empty()) pq.pop();
	memset(lst,0,sizeof(lst));
	long long i,ti=0;
	for (i=1;i<=n;i++) now[i]=s[i];
	for (i=1;i<=n;i++) pq2.push(make_pair(-t[i],i));
	for (i=1;i<=n;i++)
	{
		long long x=pq2.top().second;pq2.pop();
		while (!pq.empty()&&ti<t[x])
		{
			if (ti+now[pq.top().second]<=t[x])
			{
				ti+=now[pq.top().second];
				now[pq.top().second]=0;
				lst[pq.top().second]=ti;
				pq.pop();
			}
			else
			{
				now[pq.top().second]-=t[x]-ti;
				ti=t[x];
			}
		}
		ti=t[x];
		pq.push(make_pair(p[x],x));
	}
}
int main()
{
	ios::sync_with_stdio(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>t[i]>>s[i]>>p[i];
		if (p[i]==-1) ned=i;
			else used.insert(p[i]);
	}
	if (!used.count(0)) cand.push_back(0);
	//if (!used.count(1e9)) cand.push_back(1e9);
	for (i=1;i<=n;i++)
	{
		if (ned!=i&&!used.count(p[i]+1)) cand.push_back(p[i]+1);
	}
	sort(cand.begin(),cand.end());
//	for (set<long long>::iterator it=used.begin(),it1=used.begin();it1!=used.end()&&it!=used.end();it++,it1++)
//	{
//		if (it==it1) it1++;
	//for (i=0;i<cand.size();i++) cerr<<cand[i]<<' ';
	n++;
	t[n]=1e16;s[n]=0;p[n]=-1;
	cin>>tt;
	l=-1;r=cand.size();//r++;
	while (l<r)
	{
		mid=(l+r)/2;
		p[ned]=cand[mid];
		get();
		if (lst[ned]>=tt)
		{
			l=mid+1;
			ans=cand[mid];
		}
		else r=mid;
	}
	while (used.count(ans)) ans--;
	cout<<ans<<endl;
	p[ned]=ans;
	get();
	for (i=1;i<n;i++) cout<<lst[i]<<' ';
	cout<<endl;
	return 0;
}