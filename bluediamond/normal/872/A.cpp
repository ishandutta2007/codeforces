#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

bool x[15],y[15];

int main()
{
	int n,m;
	cin>>n>>m;
	int F,S;
	cin>>F;
	x[F]=1;
	for(int i=2;i<=n;i++)
	{
		int a;
		cin>>a;	
		x[a]=1;
		F=min(F,a);
	}
	cin>>S;
	y[S]=1;
	for(int i=2;i<=m;i++)
	{
		int a;
		cin>>a;
		y[a]=1;	
		S=min(S,a);
	}	
	for(int i=1;i<=9;i++)
		if(x[i] && y[i])
		{
			cout<<i<<"\n";
			return 0;
		}
	cout<<min(F,S)<<max(F,S)<<"\n";
	return 0;
}