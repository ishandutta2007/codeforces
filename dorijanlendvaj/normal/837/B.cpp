#include <bits/stdc++.h>

using namespace std;

int n,m;
bool a,b;
string nr,ng,nb,mr,mg,mb;
string h[1001];
string d[1001];

int main()
{
	cin>>n>>m;
	for (int i=0;i<n;++i) cin>>h[i];
	for (int j=0;j<m;++j)
	{
		for (int i=0;i<n;++i) d[j].push_back(h[i][j]);
	}
	for (int i=0;i<n;++i)
	{
		nr.push_back('R');
		ng.push_back('G');
		nb.push_back('B');
	}
	for (int i=0;i<m;++i)
	{
		mr.push_back('R');
		mg.push_back('G');
		mb.push_back('B');
	}
	a=n%3;
	a=!a && (h[0]==mr || h[0]==mg || h[0]==mb) && (h[n/3]==mr || h[n/3]==mg || h[n/3]==mb) && (h[n/3*2]==mr || h[n/3*2]==mg || h[n/3*2]==mb);
	b=m%3;
	b=!b && (d[0]==nr || d[0]==ng || d[0]==nb) && (d[m/3]==nr || d[m/3]==ng || d[m/3]==nb) && (d[m/3*2]==nr || d[m/3*2]==ng || d[m/3*2]==nb);
	for (int i=1;i<n/3;++i) a=(a && h[i]==h[i-1]);
	for (int i=n/3+1;i<n/3*2;++i) a=(a && h[i]==h[i-1]);
	for (int i=n/3*2+1;i<n;++i) a=(a && h[i]==h[i-1]);
	for (int i=1;i<m/3;++i) b=(b && d[i]==d[i-1]);
	for (int i=m/3+1;i<m/3*2;++i) b=(b && d[i]==d[i-1]);
	for (int i=m/3*2+1;i<m;++i) b=(b && d[i]==d[i-1]);
	if ((a && h[0]!=h[n/3] && h[n/3]!=h[n/3*2] && h[0]!=h[n/3*2]) || (b && d[0]!=d[m/3] && d[m/3]!=d[m/3*2] && d[0]!=d[m/3*2])) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}