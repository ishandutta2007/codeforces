#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
#define SIZE 262144
typedef vector<vector<int> >vvi;
class segtree
{
public:
	int seg[SIZE*2][4][4];
	vector<int>vinf;
	vector<int>tim(int node,vector<int>t)
	{
		vector<int>ret=vinf;
		for(int i=0;i<4;i++)for(int j=i;j<4;j++)ret[j]=min(ret[j],t[i]+seg[node][i][j]);
		return ret;
	}
	void init(string str)
	{
		for(int i=0;i<4;i++)vinf.push_back(1000000000);
		for(int i=0;i<str.size();i++)
		{
			for(int j=0;j<4;j++)for(int k=0;k<4;k++)seg[i+SIZE][j][k]=1000000000;
			seg[i+SIZE][0][0+(str[i]=='2')]=0;
			seg[i+SIZE][1][1+(str[i]=='0')]=0;
			seg[i+SIZE][2][2+(str[i]=='1')]=0;
			if(str[i]!='6')seg[i+SIZE][3][3+(str[i]=='6')]=0;
			for(int j=0;j<4;j++)seg[i+SIZE][j][j]=min(seg[i+SIZE][j][j],1);
		}
		for(int i=str.size();i<SIZE;i++)for(int j=0;j<4;j++)for(int k=0;k<4;k++)seg[i+SIZE][j][k]=1000000000*int(j!=k);
		for(int i=SIZE-1;i>=1;i--)
		{
			for(int j=0;j<4;j++)for(int k=0;k<4;k++)seg[i][j][k]=1000000000;
			for(int j=0;j<4;j++)for(int k=j;k<4;k++)for(int l=k;l<4;l++)seg[i][j][l]=min(seg[i][j][l],seg[i*2][j][k]+seg[i*2+1][k][l]);
		}
	}
	vector<int>get(int beg,int end,int node,int lb,int ub,vector<int>vec)
	{
		if(beg<=lb&&ub<=end)return tim(node,vec);
		if(end<=(lb+ub)/2)return get(beg,end,node*2,lb,(lb+ub)/2,vec);
		else if((lb+ub)/2+1<=beg)return get(beg,end,node*2+1,(lb+ub)/2+1,ub,vec);
		return get(beg,end,node*2+1,(lb+ub)/2+1,ub,get(beg,end,node*2,lb,(lb+ub)/2,vec));
	}
};
segtree tree;
int las[300000];
int s6[300000];
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	string str;
	cin>>str;
	tree.init(str);
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='7')las[i]=i;
		else if(i!=0)las[i]=las[i-1];
		else las[i]=-1000000000;
		s6[i+1]=s6[i]+(str[i]=='6');
	}
	for(int p=0;p<query;p++)
	{
		int za,zb;
		scanf("%d%d",&za,&zb);
		za--,zb--;
		if(las[zb]<za)
		{
			printf("-1\n");
			continue;
		}
		vector<int>v;
		v.push_back(0);
		v.push_back(1000000000);
		v.push_back(1000000000);
		v.push_back(1000000000);
		int r=tree.get(za,las[zb],1,0,SIZE-1,v)[3];
		if(r>=1000000000)printf("-1\n");
		else printf("%d\n",r+s6[zb+1]-s6[las[zb]]);
	}
}