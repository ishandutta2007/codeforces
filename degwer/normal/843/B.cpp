#include<stdio.h>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
typedef pair<int,int>pii;
pii ask(int t)
{
	printf("? %d\n",t);
	fflush(stdout);
	int za,zb;
	scanf("%d%d",&za,&zb);
	return make_pair(za,zb);
}
typedef long long ll;
int main()
{
	srand(time(NULL));
	int num,st,mok;
	scanf("%d%d%d",&num,&st,&mok);
	vector<pii>v;
	v.push_back(make_pair(-1,st));
	for(int i=0;i<1000;i++)
	{
		int r=((ll)rand()*32768LL+(ll)rand())%num+1;
		pii z=ask(r);
		if(z.second!=-1)v.push_back(z);
	}
	sort(v.begin(),v.end());
	int low=lower_bound(v.begin(),v.end(),make_pair(mok,-1))-v.begin()-1;
	int now=v[low].second;
	for(;;)
	{
		pii z=ask(now);
		if(z.first>=mok)
		{
			printf("! %d\n",z.first);
			fflush(stdout);
			return 0;
		}
		if(z.second==-1)
		{
			printf("! -1\n");
			fflush(stdout);
			return 0;
		}
		now=z.second;
	}
}