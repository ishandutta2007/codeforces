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
int num[4010][3];
vector<int> v;
int hv[4010];
queue<int> q;
int main()
{
	int n,n1,n2,t1;
	cin>>n;
	for(n1=1;n1<=n;n1++)
		scanf("%d%d%d",&num[n1][0],&num[n1][1],&num[n1][2]);
	for(n1=1;n1<=n;n1++)
		if(hv[n1]==0)
		{
			v.push_back(n1);
			for(n2=n1+1;n2<=n;n2++)
			{
				if(hv[n2]==1)
					continue;
				num[n2][2]-=num[n1][0];
				if(num[n2][2]<0&&hv[n2]==0)
				{
					hv[n2]=1;
					q.push(n2);
				}
				num[n1][0]--;
				if(num[n1][0]<0)
					num[n1][0]++;
			}
			while(!q.empty())
			{
				t1=q.front();
				q.pop();
				for(n2=t1+1;n2<=n;n2++)
				{
					num[n2][2]-=num[t1][1];
					if(num[n2][2]<0&&hv[n2]==0)
					{
						hv[n2]=1;
						q.push(n2);
					}
				}
			}
		}
	int sz=v.size();
	cout<<sz<<endl;
	for(n1=0;n1<sz;n1++)
		cout<<v[n1]<<' ';
}