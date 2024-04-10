#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
char map[400][400];
int rui[401][401];
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
	int mx,my,gen;
	fscanf(fr,"%d%d%d",&mx,&my,&gen);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			fscanf(fr," %c",&map[i][j]);
			rui[i+1][j+1]=rui[i+1][j]+rui[i][j+1]-rui[i][j]+(map[i][j]=='a');
		}
	}
	ll ret=0;
	for(int i=0;i<mx;i++)
	{
		for(int j=i+1;j<mx;j++)
		{
			vector<int>vec[26];
			for(int k=0;k<my;k++)
			{
				if(map[i][k]==map[j][k])
				{
					vec[map[i][k]-'a'].push_back(k);
				}
			}
			for(int l=0;l<26;l++)
			{
				if(vec[l].size()<2)
				{
					continue;
				}
				int pt=1;
				for(int k=0;k<vec[l].size();k++)
				{
					for(;;)
					{
						if(pt>=vec[l].size())
						{
							break;
						}
						if(rui[j+1][vec[l][pt]+1]-rui[j+1][vec[l][k]]-rui[i][vec[l][pt]+1]+rui[i][vec[l][k]]>gen)
						{
							break;
						}
						pt++;
					}
					ret+=max(0,pt-1-k);
				}
			}
		}
	}
	fprintf(fw,"%I64d\n",ret);
}