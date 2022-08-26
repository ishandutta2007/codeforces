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
int n,k,nopri[1000005],i,j;
vector<int> pri;
int main()
{
	cin>>n>>k;
	for (i=2;i*i<=n;i++)
	{
		if (!nopri[i])
		{
			for (j=2;i*j<=n;j++)
			{
				nopri[i*j]=1;
			}
		}
	}
	for (i=2;i<=n;i++) if (!nopri[i]) {pri.push_back(i);/*cerr<<i<<' ';*/}
	for (i=0;i<pri.size()-1;i++)
	{
		if (!nopri[pri[i]+pri[i+1]+1]&&pri[i]+pri[i+1]+1<=n) 
		{
			k--;
			//cerr<<k<<' '<<pri[i]<<' '<<pri[i+1]<<' '<<pri[i]+pri[i+1]+1<<endl;
		}
	}
	if (k<=0) cout<<"YES";
	else cout<<"NO";
	return 0;
}