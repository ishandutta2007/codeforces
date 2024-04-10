#include <bits/stdc++.h>
#define pb push_back
#define fi(x,n) for(int i=0;i<n;i++)
#define fj(x,n) for(int j=0;j<n;j++)
using namespace std;
vector <int> a[200009];
string s;
int z,o,j,x,t,c;
int main()
{
	cin>>s;
	fi(0,s.size())
	{
		s[i]-=48;
		if(s[i])
		{
			if(!j)return cout<<"-1",0;
			a[--j].pb(i+1);
		}
		else a[j++].pb(i+1);
		x=max(x,j);
	}
	if(x!=j)return cout<<"-1",0;
	cout<<x<<endl;
	fi(0,x)
	{
		cout<<a[i].size()<<" ";
		fj(0,a[i].size())cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}