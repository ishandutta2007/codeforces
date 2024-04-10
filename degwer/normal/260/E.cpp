#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef pair<int,int>pii;
int gri[2000][2000];
int rui[2001][2001];
vector<int>uni(vector<int>vec)
{
	int now=-1;
	vector<int>ret;
	for(int i=0;i<vec.size();i++)
	{
		if(now!=vec[i])
		{
			now=vec[i];
			ret.push_back(now);
		}
	}
	return ret;
}
vector<pii>unip(vector<pii>vec)
{
	pii now=make_pair(-1,-1);
	vector<pii>ret;
	for(int i=0;i<vec.size();i++)
	{
		if(now!=vec[i])
		{
			now=vec[i];
			ret.push_back(now);
		}
	}
	return ret;
}
int main()
{
	int num;
	scanf("%d",&num);
	vector<pii>vec;
	map<int,vector<int> >ma1,ma2;
	for(int i=0;i<num;i++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za*=2;
		zb*=2;
		vec.push_back(make_pair(za,zb));
		ma1[za].push_back(zb);
		ma2[zb].push_back(za);
	}
	int ans[9];
	for(int i=0;i<9;i++)
	{
		scanf("%d",&ans[i]);
	}
	sort(ans,ans+9);
	vector<pii>pa;
	vector<int>kos;
	for(;;)
	{
		kos.push_back(ans[0]+ans[1]+ans[2]);
		kos.push_back(ans[0]+ans[1]+ans[2]+ans[3]+ans[4]+ans[5]);
		pa.push_back(make_pair(ans[0]+ans[1]+ans[2],ans[0]+ans[1]+ans[2]+ans[3]+ans[4]+ans[5]));
		if(!next_permutation(ans,ans+9))
		{
			break;
		}
	}
	sort(kos.begin(),kos.end());
	sort(pa.begin(),pa.end());
	pa=unip(pa);
	kos=uni(kos);
	vector<int>lin1,lin2;
	vector<int>ba1,ba2;
	map<int,vector<int> >::iterator it1=ma1.begin(),it2=ma2.begin();
	int pt1=0,pt2=0;
	int now1=0,now2=0;
	for(;;)
	{
		if(it1==ma1.end())
		{
			break;
		}
		now1+=(*it1).second.size();
		for(;;)
		{
			if(pt1>=kos.size())
			{
				break;
			}
			if(kos[pt1]<now1)
			{
				pt1++;
			}
			else
			{
				if(kos[pt1]==now1)
				{
					lin1.push_back((*it1).first+1);
					ba1.push_back(now1);
				}
				break;
			}
		}
		it1++;
	}
	for(;;)
	{
		if(it2==ma2.end())
		{
			break;
		}
		now2+=(*it2).second.size();
		for(;;)
		{
			if(pt2>=kos.size())
			{
				break;
			}
			if(kos[pt2]<now2)
			{
				pt2++;
			}
			else
			{
				if(kos[pt2]==now2)
				{
					lin2.push_back((*it2).first+1);
					ba2.push_back(now2);
				}
				break;
			}
		}
		it2++;
	}
	for(int i=0;i<vec.size();i++)
	{
		int low1=lower_bound(lin1.begin(),lin1.end(),vec[i].first)-lin1.begin();
		int low2=lower_bound(lin2.begin(),lin2.end(),vec[i].second)-lin2.begin();
		gri[low1][low2]++;
	}
	for(int i=0;i<2000;i++)
	{
		for(int j=0;j<2000;j++)
		{
			rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+gri[i][j];
		}
	}
	for(int i=0;i<pa.size();i++)
	{
		for(int j=0;j<pa.size();j++)
		{
			int low1=lower_bound(ba1.begin(),ba1.end(),pa[i].first)-ba1.begin();
			int low2=lower_bound(ba1.begin(),ba1.end(),pa[i].second)-ba1.begin();
			int low3=lower_bound(ba2.begin(),ba2.end(),pa[j].first)-ba2.begin();
			int low4=lower_bound(ba2.begin(),ba2.end(),pa[j].second)-ba2.begin();
			int zan[9];
			zan[0]=rui[low1+1][low3+1];
			zan[1]=rui[low1+1][low4+1]-rui[low1+1][low3+1];
			zan[2]=rui[low1+1][2000]-rui[low1+1][low4+1];
			zan[3]=rui[low2+1][low3+1]-zan[0];
			zan[4]=rui[low2+1][low4+1]-zan[3]-zan[0]-zan[1];
			zan[5]=rui[low2+1][2000]-rui[low2+1][low4+1]-zan[2];
			zan[6]=rui[2000][low3+1]-rui[low2+1][low3+1];
			zan[7]=rui[2000][low4+1]-rui[low2+1][low4+1]-zan[6];
			zan[8]=rui[2000][2000]-rui[2000][low4+1]-zan[2]-zan[5];
			sort(zan,zan+9);
			bool flag=true;
			for(int i=0;i<9;i++)
			{
				flag&=(zan[i]==ans[i]);
			}
			if(flag)
			{
				printf("%lf %lf\n%lf %lf\n",double(lin1[low1])/2.0,double(lin1[low2])/2.0,double(lin2[low3])/2.0,double(lin2[low4])/2.0);
				return 0;
			}
		}
	}
	printf("-1\n");
}