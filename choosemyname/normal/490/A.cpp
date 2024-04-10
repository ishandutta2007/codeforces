#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
vector<int> v[10];
int main()
{
	int n,n1,t1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
	{
		scanf("%d",&t1);
		v[t1].push_back(n1);
	}
	int i=min(min(v[1].size(),v[2].size()),v[3].size());
	cout<<i<<endl;
	for(n1=1;n1<=i;n1++)
		cout<<v[1][n1-1]<<' '<<v[2][n1-1]<<' '<<v[3][n1-1]<<endl;
}