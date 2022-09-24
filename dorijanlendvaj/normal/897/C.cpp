#include <bits/stdc++.h>

using namespace std;

string a="What are you doing at the end of the world? Are you busy? Will you save us?";
string b="What are you doing while sending ";
string c,d;
long long l[100001];
const long long INF=1ll<<60;
int q;
long long n,k;

char rek(long long n,long long k)
{
	if (n==0) return a[k];
	if (k<b.size()) return b[k];
	if (k<b.size()+l[n-1]) return rek(n-1,k-b.size());
	if (k<b.size()+l[n-1]+c.size()) return c[k-l[n-1]-b.size()];
	if (k<b.size()+2*l[n-1]+c.size()) return rek(n-1,k-b.size()-l[n-1]-c.size());
	return d[k-b.size()-2*l[n-1]-c.size()];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	b.push_back('"');
	c.push_back('"');
	c+="? Are you busy? Will you send ";
	c.push_back('"');
	d.push_back('"');
	d.push_back('?');
	l[0]=a.size();
	for (int i=1;i<=100000;++i)
	{
		l[i]=2*l[i-1]+b.size()+c.size()+d.size();
		if (l[i]>=INF) l[i]=INF;
	}
	cin>>q;
	while (q--)
	{
		cin>>n>>k;
		if (k>l[n]) cout<<'.';
		else
		{
			cout<<rek(n,k-1);
		}
	}
}