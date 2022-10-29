#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef vector<vector<int> >vvi;
int frm[114514];
bool flag[114514];
vvi calc(vector<int>vec)
{
	fill(frm,frm+vec.size(),-1);
	fill(flag,flag+vec.size(),false);
	vector<int>v0,v1;
	for(int i=0;i<vec.size();i++)
	{
		if(vec[i]==0)
		{
			if(v1.empty())v0.push_back(i);
			else
			{
				frm[i]=v1[v1.size()-1];
				v1.pop_back();
				v0.push_back(i);
			}
		}
		else
		{
			if(v0.empty())v1.push_back(i);
			else
			{
				frm[i]=v0[v0.size()-1];
				v0.pop_back();
				v1.push_back(i);
			}
		}
	}
	vvi ret;
	for(int i=vec.size()-1;i>=0;i--)
	{
		if(!flag[i])
		{
			vector<int>now;
			int n=i;
			for(;;)
			{
				if(n==-1)break;
				now.push_back(n);
				flag[n]=true;
				n=frm[n];
			}
			reverse(now.begin(),now.end());
			ret.push_back(now);
		}
	}
	return ret;
}
int main()
{
	string s;
	cin>>s;
	vector<int>vec;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='R')vec.push_back(0);
		else vec.push_back(1);
	}
	vvi ret=calc(vec);
	vector<int>r11,r12,r21,r22;
	for(int i=0;i<ret.size();i++)
	{
		//for(int j=0;j<ret[i].size();j++)printf("%d ",ret[i][j]);printf("\n");
		if(s[ret[i][0]]=='R'&&s[ret[i][ret[i].size()-1]]=='R')r11.push_back(i);
		if(s[ret[i][0]]=='R'&&s[ret[i][ret[i].size()-1]]=='L')r12.push_back(i);
		if(s[ret[i][0]]=='L'&&s[ret[i][ret[i].size()-1]]=='R')r21.push_back(i);
		if(s[ret[i][0]]=='L'&&s[ret[i][ret[i].size()-1]]=='L')r22.push_back(i);
	}
	for(int i=0;i<min(r12.size(),r21.size());i++)
	{
		int s1=ret[r12[i]][0],t1=ret[r12[i]][ret[r12[i]].size()-1];
		int s2=ret[r21[i]][0],t2=ret[r21[i]][ret[r21[i]].size()-1];
		if(t1<t2)
		{
			ret[r12[i]].push_back(t2);
			ret[r21[i]].pop_back();
		}
		else
		{
			ret[r21[i]].push_back(t1);
			ret[r12[i]].pop_back();
		}
	}
	r11.clear();
	r12.clear();
	r21.clear();
	r22.clear();
	for(int i=0;i<ret.size();i++)
	{
		//for(int j=0;j<ret[i].size();j++)printf("%d ",ret[i][j]);printf("\n");
		if(s[ret[i][0]]=='R'&&s[ret[i][ret[i].size()-1]]=='R')r11.push_back(i);
		if(s[ret[i][0]]=='R'&&s[ret[i][ret[i].size()-1]]=='L')r12.push_back(i);
		if(s[ret[i][0]]=='L'&&s[ret[i][ret[i].size()-1]]=='R')r21.push_back(i);
		if(s[ret[i][0]]=='L'&&s[ret[i][ret[i].size()-1]]=='L')r22.push_back(i);
	}
	printf("%d\n",ret.size()-1);
	vector<int>ans;
	if(r11.size()>r22.size()||(r11.size()==r22.size()&&r12.size()>r21.size()))
	{
		for(int i=0;i<r12.size();i++)for(int j=0;j<ret[r12[i]].size();j++)ans.push_back(ret[r12[i]][j]);
		for(int i=0;i<r11.size();i++)
		{
			for(int j=0;j<ret[r11[i]].size();j++)ans.push_back(ret[r11[i]][j]);
			if(i==r11.size()-1&&s.size()%2==1)break;
			for(int j=0;j<ret[r22[i]].size();j++)ans.push_back(ret[r22[i]][j]);
		}
		for(int i=0;i<r21.size();i++)for(int j=0;j<ret[r21[i]].size();j++)ans.push_back(ret[r21[i]][j]);
	}
	else
	{
		for(int i=0;i<r21.size();i++)for(int j=0;j<ret[r21[i]].size();j++)ans.push_back(ret[r21[i]][j]);
		for(int i=0;i<r22.size();i++)
		{
			for(int j=0;j<ret[r22[i]].size();j++)ans.push_back(ret[r22[i]][j]);
			if(i==r22.size()-1&&s.size()%2==1)break;
			for(int j=0;j<ret[r11[i]].size();j++)ans.push_back(ret[r11[i]][j]);
		}
		for(int i=0;i<r12.size();i++)for(int j=0;j<ret[r12[i]].size();j++)ans.push_back(ret[r12[i]][j]);
	}
	//for(int i=0;i<s.size()-1;i++)if(s[ans[i]]==s[ans[i+1]])abort();
	for(int i=0;i<s.size();i++)
	{
		if(i!=0)printf(" ");
		printf("%d",ans[i]+1);
	}
	printf("\n");
	//for(int i=0;i<s.size();i++)printf("%c",s[ans[i]]);printf("\n");
}