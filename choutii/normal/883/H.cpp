#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
int n; string s;
char tmp[555555];
map<char,int> cnt;
string ts[555555];
#define tm tmd
map<char,int> tm;
string rearr(string x)
{
	tm.clear();
	string l,m,r;
	for(int i=0;i<x.size();++i) ++tm[x[i]];
	for(auto s:tm)
	{
		if(s.se&1) m.pb(s.fi),--s.se;
		while(s.se)
		{
			l.pb(s.fi),r.pb(s.fi),s.se-=2;
		}
	}
	reverse(r.begin(),r.end());
	return l+m+r;
}
int cc[555555];
int main()
{
	scanf("%d%s",&n,tmp); s=tmp;
	for(int i=0;i<n;++i) ++cnt[s[i]];
	int odd=0;
	for(auto s:cnt) if(s.se&1) ++odd;
	for(int i=n;i>=1;--i) //length
	{
		if(n%i) continue;
		int ha=(i&1)?(n/i):0;
		if(ha<odd) continue;
		if(!(i&1))
		{
		int g=0;
		for(auto s:cnt)
		{
			while(s.se--)
			{
				ts[g].pb(s.fi);
				if(ts[g].size()==i) ++g;
			}
		}
		}
		else
		{
		int g=0,o=0;
		for(auto s:cnt)
		{
			int ext=0;
			if(s.se&1) ext=1,--s.se,ts[o++].pb(s.fi);
			while(s.se--)
			{
				if(g<n/i&&i>1)
				{
					ts[g].pb(s.fi);++cc[g];
					if(cc[g]==i-1) ++g;
				}
				else ts[o++].pb(s.fi);
			}
		}
		}
		printf("%d\n",n/i);
		for(int j=0;j<n/i;++j)
			printf("%s ",rearr(ts[j]).c_str());
		return 0;
	}
}