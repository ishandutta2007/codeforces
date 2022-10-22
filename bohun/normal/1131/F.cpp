#include <bits/stdc++.h>
#define ll long long 
#define ld long double
using namespace std;
int n;
int id[150005],p[150005];
vector < int > v[150005];
int fin(int x)
{
	if(x!=p[x])
		p[x]=fin(p[x]);
	return p[x];
}
void onion(int x,int y)
{
	if(fin(x)!=fin(y))
	{
		int xx=fin(x);
		int yy=fin(y);
		if(v[xx].size()>v[yy].size())
		{
			for(auto it: v[yy])
				v[xx].push_back(it);
			p[yy]=xx;
		}
		else
		{
			for(auto it: v[xx])
				v[yy].push_back(it);
			p[xx]=yy;
		}
	}
}
		
int main()
{	
	cin>>n;
	for(int i=1;n>=i;i++)
	{
		p[i]=i;
		v[i].push_back(i);
	}
	for(int i=1;n-1>=i;i++)
	{
		int a,b;
		cin>>a>>b;
		onion(a,b);
	}
	for(auto it: v[fin(1)])
		cout<<it<<" ";
		
    return 0;	
}