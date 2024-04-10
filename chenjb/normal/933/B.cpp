#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstdlib>
using namespace std;
long long p,k;
long long save[110000];
int main()
{
	cin>>p>>k;
	int n=0;
	while (p)
	{
		if(n%2==1)
		{
			if(p%k==0)save[++n]=0; else save[++n]=k-(p%k);
			p=(p-1)/k+1;
		}
		else save[++n]=p%k,p=p/k;
	}
	cout<<n<<endl;
	for(int i=1;i<=n;i++)printf("%lld%c",save[i],i==n?'\n':' ');
	return 0;
}