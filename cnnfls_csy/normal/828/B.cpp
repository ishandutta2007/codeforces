#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,mix=1<<25,miy=1<<25,mxx,mxy,used;
char ch;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			cin>>ch;
			if (ch=='B')
			{
				mix=min(mix,i);
				miy=min(miy,j);
				mxx=max(mxx,i);
				mxy=max(mxy,j);
				used++;
			}
		}
	}
	cerr<<mix<<' '<<miy<<' '<<mxx<<' '<<mxy<<endl;
	if (!mxx&&!mxy&&mix>(1<<24)&&miy>(1<<24))
	{
		cout<<1;
		return 0;
	}
	if (max(mxx-mix,mxy-miy)+1>n||max(mxx-mix,mxy-miy)+1>m)
	{
		cout<<-1;
		return 0;
	}
	//cerr<<sqr(max(mix-mxx,miy-mxy))<<endl;
	//cout<<sqr(min(mix-mxx,miy-mxy))-used;
	cout<<sqr(max(mxx-mix,mxy-miy)+1)-used;
	return 0;
}