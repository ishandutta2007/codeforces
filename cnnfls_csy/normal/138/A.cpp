#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
bool aaaa=1,aabb=1,abab=1,abba=1;
int n,m,i,j,k,l;
string st[10005],ans;
set<char> y;
string tp[5]={"","aaaa","abab","abba","aabb"};
int main()
{
	y.insert('a');
	y.insert('e');
	y.insert('i');
	y.insert('o');
	y.insert('u');
	cin>>n>>m;	
	for (l=1;l<=4*n;l++)
	{
		cin>>st[l];
		k=0;
		for (j=st[l].length()-1;j>=0&&k<m;j--)
		{
			k+=y.count(st[l][j]);
			if (k>=m) break;
			//cerr<<j<<' '<<k<<endl;
		}
		if (k<m) {cout<<"NO";return 0;}
		//cerr<<j<<' ';
		st[l]=st[l].substr(j);
		//cerr<<st[l]<<endl;
	}
	bool ok=0,ok1;
	for (i=1;i<=4;i++)
	{
		ok1=1;
		for (j=1;j<=n;j++)
		{
			for (k=1;k<=4;k++)
			{
				for (l=1;l<=4;l++)
				{
					if (tp[i][k-1]==tp[i][l-1]&&st[(j-1)*4+k]!=st[(j-1)*4+l]) 
					{
						ok1=0;
						//cerr<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
					}
				}
			}
		}
		if (ok1&&!ok) {ok=1;ans=tp[i];}
	}
	if (!ok) cout<<"NO";
	else cout<<ans;
	return 0;
}