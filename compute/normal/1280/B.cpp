#include<bits/stdc++.h>
using namespace std;
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
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int r,c;
		cin>>r>>c;
		vc<string> maze(r);
		bool allp=1,alla=1;
		bool aonedge=0;
		for(int i=0;i<r;i++)
		{
			cin>>maze[i];
			for(int j=0;j<c;j++)
			{
				if(maze[i][j]=='P') 
					alla=0;
				else if(maze[i][j]=='A')
				{
					allp=0;
					if(i==0||j==0||j==c-1||i==r-1) aonedge=1;
				}
			}
		}
		bool aonc=0;
		if(maze[0][0]=='A'||maze[r-1][c-1]=='A'||maze[0][c-1]=='A'||maze[r-1][0]=='A') aonc=1;
		if(allp) cout<<"MORTAL\n";
		else if(alla) cout<<"0\n";
		else{
			if(!aonedge) cout<<"4\n";
			else{
				bool midline=0;
				bool sideline=0;
				for(int i=0;i<r;i++)
				{
					int cnt=0;
					for(int j=0;j<c;j++)
						cnt+=(maze[i][j]=='A');
					if(cnt==c)
					{
						if(i==0||i==r-1) sideline=1;
						else midline=1;
					}
				}
				for(int i=0;i<c;i++)
				{
					int cnt=0;
					for(int j=0;j<r;j++)
						cnt+=(maze[j][i]=='A');
					if(cnt==r)
					{
						if(i==0||i==c-1) sideline=1;
						else midline=1;
					}
				}
				if(sideline) cout<<"1\n";
				else if(midline||aonc) cout<<"2\n";
				else{
					cout<<"3\n";
				}
			}
		}

	}
}