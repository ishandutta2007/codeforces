#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<deque>
#define sqr(x) (x)*(x)
#define llx(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
vector<long long> seq[505],all;
long long n,m,i,j,b,b2,sum[505][5],x[100005],ans,cnt;
string op[100005];
void rest(int x)
{
	memset(sum[x],0,sizeof(sum[x]));
	int cnt=0;
	llx(seq[x],it)
	{
		sum[x][cnt]+=all[*it];
		(cnt+=1)%=5;
	}
}
int main()
{
	scanf("%I64d",&n);
	for (i=1;i<=n;i++)
	{
		scanf(" ");
		rdst(op[i],3);
		if (op[i]=="sum") x[i]=-1;
		else
		{
			scanf("%I64d",&x[i]);
			all.push_back(x[i]);
		}
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	b=sqrt((long long)all.size())+1;
	b2=((long long)all.size()-1)/b;
	for (i=1;i<=n;i++)
	{
		if (op[i]=="sum")
		{
			ans=cnt=0;
			for (j=0;j<=b2;j++)
			{
				ans+=sum[j][((2-cnt)%5+5)%5];
				cnt+=seq[j].size();
			}
			printf("%I64d\n",ans);
		}
		x[i]=lower_bound(all.begin(),all.end(),x[i])-all.begin();
		if (op[i]=="add")
		{
			seq[x[i]/b].insert(upper_bound(seq[x[i]/b].begin(),seq[x[i]/b].end(),x[i]),x[i]);
			rest(x[i]/b);
		}
		if (op[i]=="del")
		{
			seq[x[i]/b].erase(lower_bound(seq[x[i]/b].begin(),seq[x[i]/b].end(),x[i]));
			rest(x[i]/b);
		}
	}
	return 0;
}