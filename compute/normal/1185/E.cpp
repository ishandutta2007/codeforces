#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2005;
const int INF=0x3f3f3f3f;
char maze[maxn][maxn];
struct Point{
	int r,c;
	bool operator<(const Point &a)const{
		if(r==a.r) return c<a.c;
		return r<a.r;
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		vector<Point> ch[26];
		int n,m;
		scanf("%d%d",&n,&m);
		Point o={-1,-1};
		int mi=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]>='a'&&maze[i][j]<='z')
				{
					ch[maze[i][j]-'a'].push_back(Point {i,j});
					if(maze[i][j]-'a'>mi)
					{
						mi=maze[i][j]-'a';
						o={i,j};
					}
				}
			}
		}
		bool ok=1;
		vector<pair<Point,Point> > ans;
		for(int i=0;i<=mi;i++)
		{
			sort(ch[i].begin(),ch[i].end());
			if(!ch[i].size())
			{
				ans.push_back(make_pair(o,o));
				continue;
			}
			bool sr=1,sc=1;
			for(int j=1;j<ch[i].size();j++)
			{
				Point cur=ch[i][j];
				Point pre=ch[i][j-1];
				if(pre.r!=cur.r) sr=0;
				if(pre.c!=cur.c) sc=0;
			}
			if(sr&&sc) 
			{
				ans.push_back(make_pair(ch[i][0],ch[i][0]));
			}
			else if(sr)
			{
				int row=ch[i][0].r;
				int ma=ch[i][ch[i].size()-1].c,le=ch[i][0].c;
				ans.push_back(make_pair(Point{row,le},Point{row,ma}));
			}
			else if(sc)
			{
				int col=ch[i][0].c;
				int ma=ch[i][ch[i].size()-1].r,le=ch[i][0].r;
				ans.push_back(make_pair(Point{le,col},Point{ma,col}));
			}
			else{
				ok=0;
			}
		}
		dbg(233);
		if(ok)
		{
			for(int i=mi;i>=0;i--)
			{
				for(int ii=ans[i].first.r;ii<=ans[i].second.r;ii++)
				{
					for(int jj=ans[i].first.c;jj<=ans[i].second.c;jj++)
					{
						if(maze[ii][jj]-'a'!=i&&maze[ii][jj]!='?')
						{
						    ok=0;
						    break;
						}
						else maze[ii][jj]='?';
					}
					if(!ok) break;
				}
				if(!ok) break;
			}
		}
		if(ok)
		{
			puts("Yes");
			printf("%d\n",mi+1);
			for(int i=0;i<=mi;i++)
			{
				printf("%d %d %d %d\n",ans[i].first.r+1,ans[i].first.c+1,ans[i].second.r+1,ans[i].second.c+1);
			}
		}
		else puts("NO");
	}
}