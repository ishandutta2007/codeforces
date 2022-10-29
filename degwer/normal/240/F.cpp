#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#define SIZE 131072
using namespace std;
class segtree
{
public:
	int seg[SIZE*2];
	bool flag[SIZE*2];
	int update(int beg,int end,int node,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return seg[node];
		}
		if(beg<=lb&&ub<=end)
		{
			flag[node]=true;
			return seg[node]=num*(ub-lb+1);
		}
		if(flag[node])
		{
			seg[node*2]=seg[node]/2;
			flag[node*2]=true;
			seg[node*2+1]=seg[node]/2;
			flag[node*2+1]=true;
			flag[node]=false;
		}
		return seg[node]=update(beg,end,node*2,lb,(lb+ub)/2,num)+update(beg,end,node*2+1,(lb+ub)/2+1,ub,num);
	}
	int sum(int beg,int end,int node,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return 0;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[node];
		}
		if(flag[node])
		{
			seg[node*2]=seg[node]/2;
			flag[node*2]=true;
			seg[node*2+1]=seg[node]/2;
			flag[node*2+1]=true;
			flag[node]=false;
		}
		return sum(beg,end,node*2,lb,(lb+ub)/2)+sum(beg,end,node*2+1,(lb+ub)/2+1,ub);
	}
};
segtree tree[26];
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
	int len,query;
	fscanf(fr,"%d%d",&len,&query);
	string str;
	for(int i=0;i<len;i++)
	{
		char zan;
		fscanf(fr," %c",&zan);
		str.push_back(zan);
	}
	for(int i=0;i<26;i++)
	{
		fill(tree[i].flag,tree[i].flag+SIZE*2,false);
	}
	for(int i=0;i<str.size();i++)
	{
		tree[str[i]-'a'].update(i,i,1,0,SIZE-1,1);
	}
	for(int p=0;p<query;p++)
	{
		int za,zb;
		fscanf(fr,"%d%d",&za,&zb);
		za--;
		zb--;
		int hai[26];
		fill(hai,hai+26,0);
		int numodd=0,rr;
		for(int i=0;i<26;i++)
		{
			hai[i]=tree[i].sum(za,zb,1,0,SIZE-1);
			numodd+=hai[i]%2;
			if(hai[i]%2)
			{
				rr=i;
			}
		}
		if(numodd>=2)
		{
			continue;
		}
		for(int i=0;i<26;i++)
		{
			tree[i].update(za,zb,1,0,SIZE-1,0);
		}
		if(numodd==1)
		{
			tree[rr].update((za+zb)/2,(za+zb)/2,1,0,SIZE-1,1);
			hai[rr]--;
		}
		int now=0;
		for(int i=0;i<26;i++)
		{
			if(hai[i]!=0)
			{
				tree[i].update(za+now,za+now+hai[i]/2-1,1,0,SIZE-1,1);
				tree[i].update(zb-now-hai[i]/2+1,zb-now,1,0,SIZE-1,1);
				now+=hai[i]/2;
			}
		}
	}
	string ret;
	ret.resize(len);
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(tree[j].sum(i,i,1,0,SIZE-1))
			{
				ret[i]=j+'a';
			}
		}
	}
	for(int i=0;i<len;i++)
	{
		fprintf(fw,"%c",ret[i]);
	}
	fprintf(fw,"\n");
}