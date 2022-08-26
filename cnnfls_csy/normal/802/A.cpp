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
int n,m,i,j,x,k,s,z,fi[1005],us[1005];
vector<int> lib,no;
int main()
{
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>fi[i];
	}
	for (i=1;i<=n;i++)
	{
		if (i>1) lib.push_back(fi[i-1]);
		sort(lib.begin(),lib.end());
		if (!binary_search(lib.begin(),lib.end(),fi[i])) {lib.push_back(fi[i]);s++;/*cerr<<"000000\n"*/;}
		sort(lib.begin(),lib.end());
		//lib.push_back(fi[i]);
		if (lib.size()>m)
		{
			memset(us,0,sizeof(us));
			//cerr<<i<<endl;
			int c=1e8;
			for (j=i;j<=n;j++)
			{
				if (!us[fi[j]]) us[fi[j]]=--c;
			//	cerr<<"x"<<fi[j]<<us[fi[j]]<<us[1];
			}
			/*for (j=1;j<=n;j++)
			{
				cerr<<us[j];
			}
			cerr<<endl;*/
			no=lib;
			//cerr<<no.size()<<endl;
			lib.clear();
			while (lib.size()<m)
			{
				/*for (j=0;j<no.size();j++)
				{
					cerr<<no[j]<<' ';
				}
				cerr<<endl;*/
				int ma=-1,ms;
				for (j=1;j<=n;j++)
				{
					if (us[j]>ma) {ma=us[j];ms=j;}
				}
				//cerr<<ms<<endl;
				if (binary_search(no.begin(),no.end(),ms))
				{
					lib.push_back(ms);
					no.erase(lower_bound(no.begin(),no.end(),ms));
				}
				us[ms]=-1;
			}
		}
		sort(lib.begin(),lib.end());
		/*for (j=0;j<lib.size();j++)
		{
			cerr<<lib[j]<<' ';
		}*/
		//cerr<<endl;
		lib.erase(lower_bound(lib.begin(),lib.end(),fi[i]));
	}
	cout<<s;
	return 0;
}