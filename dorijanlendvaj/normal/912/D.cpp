#include <bits/stdc++.h>

using namespace std;

long long n,m,r,k;
long long zb,uz;
long long a[100001],b[100001];
priority_queue<pair<long long,pair<int,int> > > q;
map<int,bool> bio[100001];

void dijkstra()
{
	q.push({a[0]*b[0],{0,0}});
	while (uz<k)
	{
		//cout<<q.top().first<<endl;
		int i=q.top().second.first,j=q.top().second.second,l=q.top().first;
		q.pop();
		if (bio[i][j]) continue;
		zb+=l;
		++uz;
		//cout<<i<<' '<<j<<endl;
		bio[i][j]=1;
		if (i<n-1 && !bio[i+1][j]) q.push({a[i+1]*b[j],{i+1,j}});
		if (j<m-1 && !bio[i][j+1]) q.push({a[i]*b[j+1],{i,j+1}});
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m>>r>>k;
	int r1=r,r2=r;
	if (r*2-1>n) r1=n-r+1;
	if (r*2-1>m) r2=m-r+1;
	for (int i=0;i<r1-1;++i)
	{
		a[i]=i+1;
		a[n-i-1]=i+1;
	}
	for (int i=0;i<r2-1;++i)
	{
		b[i]=i+1;
		b[m-i-1]=i+1;
	}
	for (int i=r1-1;i<=n-r1;++i) a[i]=r1;
	for (int i=r2-1;i<=m-r2;++i) b[i]=r2;
	//for (int i=0;i<n;++i) cout<<a[i]<<' ';
	//cout<<endl;
	//for (int i=0;i<m;++i) cout<<b[i]<<' ';
	//cout<<endl;
	sort(a,a+n);
	sort(b,b+m);
	reverse(a,a+n);
	reverse(b,b+m);
	dijkstra();
	cout<<fixed<<setprecision(11)/*<<zb<<' '<<(n-r+1)*(m-r+1)<<' '*/<<zb*1./((n-r+1)*(m-r+1))<<endl;
}