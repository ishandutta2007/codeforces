#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
	int numa,numb;
	fscanf(fr,"%d",&numa);
	vector<int>va,vb;
	for(int i=0;i<numa;i++)
	{
		int zan;
		fscanf(fr,"%d",&zan);
		va.push_back(zan);
	}
	fscanf(fr,"%d",&numb);
	for(int i=0;i<numb;i++)
	{
		int zan;
		fscanf(fr,"%d",&zan);
		vb.push_back(zan);
	}
	reverse(va.begin(),va.end());
	reverse(vb.begin(),vb.end());
	vector<int>vec;
	vector<int>ret;
	int now=0;
	int pta=0,ptb=0;
	for(;;)
	{
		for(;;)
		{
			if(pta==numa)
			{
				break;
			}
			if(now==va[pta])
			{
				vec.push_back(now);
				ret.push_back(va.size()-pta);
				pta++;
			}
			else
			{
				break;
			}
		}
		for(;;)
		{
			if(ptb==numb)
			{
				break;
			}
			if(now==vb[ptb])
			{
				vec.push_back(now);
				ret.push_back(va.size()+vb.size()-ptb);
				ptb++;
			}
			else
			{
				break;
			}
		}
		if(pta==va.size()&&ptb==vb.size())
		{
			break;
		}
		now=!now;
	}
	reverse(ret.begin(),ret.end());
	reverse(vec.begin(),vec.end());
	for(int i=0;i<ret.size();i++)
	{
		if(i!=0)
		{
			fprintf(fw," ");
		}
		fprintf(fw,"%d",ret[i]);
	}
	fprintf(fw,"\n");
	vec.push_back(0);
	vector<int>ans;
	for(int i=0;i<va.size()+vb.size();i++)
	{
		if(vec[i]!=vec[i+1])
		{
			ans.push_back(i+1);
		}
	}
	fprintf(fw,"%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0)
		{
			fprintf(fw," ");
		}
		fprintf(fw,"%d",ans[i]);
	}
	fprintf(fw,"\n");
}