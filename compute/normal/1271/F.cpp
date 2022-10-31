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
typedef pair<int,int> pi;
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

int a[2],b[2],c[2];
int d[8];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a[0]>>b[0]>>c[0];
		cin>>a[1]>>b[1]>>c[1];
		for(int i=1;i<=7;i++) cin>>d[i];
		bool ok=0;
		int ans[8];
		for(int i=0;i<=d[2];i++)
		{
			for(int j=0;j<=d[3];j++)
			{
				for(int k=0;k<=d[5];k++)
				{
					int aa=i+j,bb=i+k,cc=j+k;
					int aa2=d[2]-i+d[3]-j,bb2=d[2]-i+d[5]-k,cc2=d[3]-j+d[5]-k;
					if(aa<=a[0]&&bb<=b[0]&&cc<=c[0]&&aa2<=a[1]&&bb2<=b[1]&&cc2<=c[1])
					{
						if(aa+aa2+d[4]+d[1]<=a[0]+a[1]&&bb+bb2+d[6]+d[1]<=b[0]+b[1]&&cc+cc2+d[7]+d[1]<=c[0]+c[1])
						{
							if(d[1]<=min({a[0]-aa,b[0]-bb,c[0]-cc})+min({a[1]-aa2,b[1]-bb2,c[1]-cc2}))
							{
								ok=1;
								ans[2]=i,ans[3]=j,ans[5]=k;
								ans[1]=min({a[0]-aa,b[0]-bb,c[0]-cc,d[1]});
								aa=i+j+ans[1],bb=i+k+ans[1],cc=j+k+ans[1];
								ans[4]=min(a[0]-aa,d[4]);
								ans[6]=min(b[0]-bb,d[6]);
								ans[7]=min(c[0]-cc,d[7]);
							}
						}
					}
				}
				if(ok) break;
			}
			if(ok) break;
		}
		if(!ok) cout<<"-1\n";
		else{
			for(int i=1;i<=7;i++) cout<<ans[i]<<" ";
			cout<<'\n';
		}
	}
}