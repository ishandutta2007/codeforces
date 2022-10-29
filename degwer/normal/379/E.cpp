#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
double ans[300];
vector<double>dat[300];
typedef pair<double,double>pdd;
double eps=1e-9;
int main()
{
	int num,kai;
	scanf("%d%d",&num,&kai);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<=kai;j++)
		{
			int z;
			scanf("%d",&z);
			dat[i].push_back(z);
		}
	}
	for(int i=0;i<kai;i++)
	{
		vector<pdd>vec;
		vec.push_back(make_pair(0,0));
		vec.push_back(make_pair(1,0));
		for(int j=0;j<num;j++)
		{
			vector<pdd>add;
			double a=dat[j][i],b=dat[j][i+1];
			for(int k=0;k<vec.size()-1;k++)
			{
				double t1=vec[k].first,t2=vec[k+1].first;
				double s1=vec[k].second,s2=vec[k+1].second;
				double d1=a+(b-a)*t1,d2=a+(b-a)*t2;
				if(d1<s1&&d2>s2)
				{
					double x=t1+(t2-t1)*(s1-d1)/((d2-s2)+(s1-d1));
					ans[j]+=(d2-s2)*(t2-x)/2.0;
					add.push_back(vec[k]);
					add.push_back(make_pair(x,a+(b-a)*x));
					add.push_back(make_pair(t2,d2));
				}
				else if(d2<s2&&d1>s1)
				{
					double x=t1+(t2-t1)*(d1-s1)/((d1-s1)+(s2-d2));
					ans[j]+=(d1-s1)*(x-t1)/2.0;
					add.push_back(make_pair(t1,d1));
					add.push_back(make_pair(x,a+(b-a)*x));
					add.push_back(vec[k+1]);
				}
				else if(s1<d1||s2<d2)
				{
					ans[j]+=((d1-s1)+(d2-s2))*(t2-t1)/2.0;
					add.push_back(make_pair(t1,d1));
					add.push_back(make_pair(t2,d2));
				}
				else
				{
					add.push_back(vec[k]);
					add.push_back(vec[k+1]);
				}
			}
			vec.clear();
			vec.push_back(add[0]);
			for(int k=1;k<add.size();k++)
			{
				if(add[k].first-add[k-1].first>eps)vec.push_back(add[k]);
			}
			/*for(int k=0;k<add.size();k++)
			{
				printf("%lf %lf\n",add[k].first,add[k].second);
			}
			printf("\n");*/
		}
	}
	for(int i=0;i<num;i++)printf("%.15lf\n",ans[i]);
}