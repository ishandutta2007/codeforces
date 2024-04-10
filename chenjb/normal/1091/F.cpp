#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <cassert>
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
using namespace std;
long long l[110000],a[110000],b[110000];
int c[110000],save[110000];
char s[110000];
int n,i,pre,tot;
long long ans;
set<pair<int,pair<int,long long> > > dic;
int cmp(int a,int b) { return c[a]<c[b]; }
void init()
{
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&l[i]);
	scanf("%s",s+1);
}
int main() 
{
	init();

	rep(i,n)
	{ 
		if (s[i]=='G'){ dic.insert(mp(0,mp(i,l[i]))); continue; }
		if (s[i]=='W'){ dic.insert(mp(1,mp(i,l[i]))),pre=1; continue; }
		if (s[i]=='L')
		{
			long long p=l[i];
			while (p) 
			{
					if (dic.size()==0)break;
					auto tt=dic.end(); tt--;
					pair<int,pair<int,long long> > x=*tt;

					dic.erase(tt);

					long long t;
					if (x.second.second<p)t=x.second.second; else t=p;
					if (!x.first)ans=ans+6*t; else ans=ans+4*t;
					if (x.second.second>p) 
					{
						x.second.second-=p;
						dic.insert(x);
						p=0;
						break;
					}
					p-=x.second.second;
			}
			if (p) 
			{	
				if(pre) ans+=1ll*4*p;
				else ans+=1ll*6*p;
			}
			continue;
		}
	}
	for (auto p:dic)a[++tot]=p.first,b[tot]=p.second.second,c[tot]=p.second.first;

	for (i=1;i<=tot;++i) save[i]=i;
	sort(save+1,save+tot+1,cmp); 
	long long now=0;
	while (i>=1)
	{
		long long p=save[i];
		if (a[p]==0) now+=b[p];
		else 
		{
			if (now>=b[p])ans+=4ll*b[p]; else ans+=(2ll*now+2ll*b[p]);
			if (now>=b[p])now-=b[p];
			else b[p]-=now,now=0;
		}	
		i--;
	}
	ans=ans+3ll*now;
	cout<<ans<<endl;
}