#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<double,double>pdd;
typedef pair<double,pdd>pd3;
int main()
{
	int num;
	scanf("%d",&num);
	vector<pd3>vec;
	double ans=0,nowtim=0;
	for(int i=0;i<num;i++)
	{
		double za,zb;
		scanf("%lf%lf",&za,&zb);
		ans+=za;
		nowtim+=1.0-zb/100.0;
		vec.push_back(make_pair((100.0-zb)/(za*zb),make_pair(za,zb/100.0)));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<num;i++)
	{
		nowtim-=1.0-vec[i].second.second;
		ans+=nowtim*vec[i].second.first*vec[i].second.second;
	}
	printf("%lf\n",ans);
}