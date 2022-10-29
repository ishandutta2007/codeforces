#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
typedef pair<int,int>pii;
typedef pair<double,double>pdd;
int main()
{
	int numa,numb;
	double la,lb;
	scanf("%d%d%lf%lf",&numa,&numb,&la,&lb);
	vector<double>va;
	vector<pdd>vb;
	for(int i=0;i<numa;i++)
	{
		double zan;
		scanf("%lf",&zan);
		va.push_back(zan);
	}
	for(int i=0;i<numb;i++)
	{
		double zan;
		scanf("%lf",&zan);
		vb.push_back(make_pair(zan,0));
	}
	for(int i=0;i<numb;i++)
	{
		double zan;
		scanf("%lf",&zan);
		vb[i].second=zan;
	}
	double mini=1000000000000000000000.0;
	int reta=-1,retb=-1;
	for(int i=0;i<numb;i++)
	{
		int low=lower_bound(va.begin(),va.end(),vb[i].first/lb*la)-va.begin();
		double ret=vb[i].second+sqrt((vb[i].first-va[low])*(vb[i].first-va[low])+(lb-la)*(lb-la))+sqrt(la*la+va[low]*va[low]);
		if(low!=0)
		{
			if(ret>vb[i].second+sqrt((vb[i].first-va[low-1])*(vb[i].first-va[low-1])+(lb-la)*(lb-la))+sqrt(la*la+va[low-1]*va[low-1]))
			{
				ret=vb[i].second+sqrt((vb[i].first-va[low-1])*(vb[i].first-va[low-1])+(lb-la)*(lb-la))+sqrt(la*la+va[low-1]*va[low-1]);
				low--;
			}
		}
		if(ret<mini)
		{
			mini=ret;
			reta=low+1;
			retb=i+1;
		}
	}
	printf("%d %d\n",reta,retb);
}