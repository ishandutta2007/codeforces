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
int x[110][110];
char p[110][110];
int main()
{
	int n,m,n1,n2,n3,n4;
	cin>>n>>m;
	for(n1=1;n1<=n;n1++)
		scanf("%s",p[n1]+1);
	int ans=0;
	for(n1=n;n1>=1;n1--)
		for(n2=m;n2>=1;n2--)
		{
			if(p[n1][n2]=='B')
			{
				if(x[n1][n2]==-1)
					continue;
				for(n3=1;n3<=n1;n3++)
					for(n4=1;n4<=n2;n4++)
						x[n3][n4]+=(-1-x[n1][n2]);
				ans++;
			}
			if(p[n1][n2]=='W')
			{
				if(x[n1][n2]==1)
					continue;
				for(n3=1;n3<=n1;n3++)
					for(n4=1;n4<=n2;n4++)
						x[n3][n4]+=(1-x[n1][n2]);
				ans++;	
			}
		}
	cout<<ans;
}