#include<bits/stdc++.h>
using namespace std;
long long a,qzhr[1003],qzhc[1003],n,m,k,p,sumr[1000003],sumc[1000003];
priority_queue<long long>q;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>p;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>a;
			qzhr[i]+=a;
			qzhc[j]+=a;
		}
	for(int i=0;i<n;i++)q.push(qzhr[i]);
	for(int i=0;i<k;i++)
	{
		long long x=q.top();
		q.pop();
		sumr[i+1]=x+sumr[i];
		q.push(x-m*p);
	}
	while(!q.empty())q.pop();
	for(int i=0;i<m;i++)q.push(qzhc[i]);
	for(int i=0;i<k;i++)
	{
		long long x=q.top();
		q.pop();
		sumc[i+1]=sumc[i]+x;
		q.push(x-n*p);
	}
	long long ans=-123456789101112131;
	for(int i=0;i<=k;i++)
		ans=max(ans,sumc[i]+sumr[k-i]-i*(k-i)*p*1ll);// (i(k-i)p) 
	cout<<ans;
}