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
char s[55][55];
int p[200];
int main()
{
	int n,m,n1,n2;
	cin>>n>>m;
	for(n1=1;n1<=n;n1++)
		cin>>s[n1]+1;
	int ans=0;
	for(n1=1;n1<n;n1++)
		for(n2=1;n2<m;n2++)
		{
			memset(p,0,sizeof(p));
			p[s[n1][n2]]++;
			p[s[n1][n2+1]]++;
			p[s[n1+1][n2]]++;
			p[s[n1+1][n2+1]]++;
			if(p['f']&&p['a']&&p['c']&&p['e'])
				ans++;
		}
	cout<<ans;
}