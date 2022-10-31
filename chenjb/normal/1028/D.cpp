#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x1 gtmsub
#define y1 gtmshb
#define x2 gtmjtjl
#define y2 gtmsf
#define mod 1000000007
using namespace std;
set<int> sell,buy;
set<int> unsure;
int n;
char s[20];
int sump;
int main()
{
	cin>>n;
	sell.clear();
	buy.clear();
	unsure.clear();
	int sump=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int x; scanf("%d",&x);
		if (s[1]=='D') //ADD
		{
			int minsell,maxbuy;
			if (sell.size()==0)minsell=2147483647; else minsell=*sell.begin();
			if (buy.size()==0)maxbuy=-2147483647; else { auto it=buy.end(); it--; maxbuy=*it; }
			if (x>minsell)sell.insert(x);
			else if (x<maxbuy)buy.insert(x);
			else unsure.insert(x);
		}
		else // ACCEPT
		{
			int minsell,maxbuy;
			if (sell.size()==0)minsell=2147483647; else minsell=*sell.begin();
			if (buy.size()==0)maxbuy=-2147483647; else { auto it=buy.end(); it--; maxbuy=*it; }
			if (unsure.find(x)!=unsure.end()){ sump=sump*2%mod; unsure.erase(x); }
			if (sell.find(x)!=sell.end() && minsell!=x){ puts("0"); return 0; }
			if (buy.find(x)!=buy.end() && maxbuy!=x){ puts("0"); return 0; }
			if (minsell==x)sell.erase(x);
			if (maxbuy==x)buy.erase(x);
			for(auto p:unsure)
				if (p<x)buy.insert(p); else sell.insert(p);
			unsure.clear();
		}
	}
	cout<<1ll*(unsure.size()+1)*sump%mod<<endl;
}