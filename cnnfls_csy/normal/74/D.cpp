#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x,y,z,op,rt=0,l,r,l1,l2,r1,r2,mid;
set<int> used;
//map<pair<int,int>,int> len;
//map<pair<int,pair<int,int>/**/>,int> mp;
set<pair<int,pair<int,int>/**/>/**/> s;
set<pair<int,int>/**/> s2;
map<int,int> ltor,rtol,pos;
//map<int,pair<int,int>/**/> tolr;
vector<int> all;
vector<pair<bool,pair<int,int>/**/>/**/> zhi;
struct bit
{
	int num[200005];
	int lowbit(int x) {return x&(-x);}
	void add(int x,int y)
	{
		int i;
		for (i=x;i<=200000;i+=lowbit(i)) num[i]+=y;
	}
	int query(int x)
	{
		int s=0,i;
		for (i=x;i>0;i-=lowbit(i)) s+=num[i];
		return s;
	}
}sum;
vector<int> uniq(vector<int> all)
{
	if (all.empty()) return all;
	vector<int> all2;
	sort(all.begin(),all.end());
	all2.push_back(all[0]);
	int i;
	for (i=1;i<all.size();i++) if (all[i]!=all[i-1]) all2.push_back(all[i]);
	return all2;
}
int main()
{
	scanf("%d%d",&n,&m);
//	len[make_pair(1,n)]=n;
	s.insert(make_pair(n,make_pair(1,n)));
	s2.insert(make_pair(1,n));
//	mp[make_pair(n,make(1,n))]=0;
	ltor[1]=n;rtol[n]=1;
	for (i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if (x==-1)
		{
			for (set<pair<int,pair<int,int>/**/>/**/>::iterator it=s.begin();it!=s.end();it++) cerr<<it->first<<' '<<it->second.first<<' '<<it->second.second<<endl;
		}
		else if (x)
		{
			if (!used.count(x))
			{
				used.insert(x);
				set<pair<int,pair<int,int>/**/>/**/>::iterator it=s.end();it--;
				l=it->second.first;
				r=it->second.second;
				mid=(l+r+1)/2;
				ltor[l]=mid-1;rtol[r]=mid+1;
				ltor[mid+1]=r;rtol[mid-1]=l;
				pos[x]=mid;
				zhi.push_back(make_pair(1,make_pair(mid,1)));
				all.push_back(mid);
				s.erase(it);
				s2.erase(make_pair(l,r));
				s.insert(make_pair(mid-l,make_pair(l,mid-1)));
				s.insert(make_pair(r-mid,make_pair(mid+1,r)));
				s2.insert(make_pair(l,mid-1));
				s2.insert(make_pair(mid+1,r));
			}
			else
			{
				used.erase(x);
				int tpos=pos[x];
				zhi.push_back(make_pair(1,make_pair(tpos,-1)));
				l1=rtol[tpos-1];r1=tpos-1;
				l2=tpos+1;r2=ltor[tpos+1];
				s.erase(make_pair(r1-l1+1,make_pair(l1,r1)));
				s.erase(make_pair(r2-l2+1,make_pair(l2,r2)));
				s.insert(make_pair(r2-l1+1,make_pair(l1,r2)));
				s2.erase(make_pair(l1,r1));
				s2.erase(make_pair(l2,r2));
				s2.insert(make_pair(l1,r2));
				pos.erase(x);
				ltor[l1]=r2;
				rtol[r2]=l1;
				ltor.erase(l2);
				rtol.erase(r1);
			}
		}
		else
		{
			scanf("%d%d",&l,&r);
			zhi.push_back(make_pair(0,make_pair(l-1,r)));
			all.push_back(l-1);
			all.push_back(r);
		}
	}
	all=uniq(all);
	/*for (i=0;i<all.size();i++) cerr<<all[i]<<' ';cerr<<endl;
	for (i=0;i<zhi.size();i++)
	{
		cerr<<zhi[i].first<<' '<<zhi[i].second.first<<' '<<zhi[i].second.second<<endl;
		if (!zhi[i].first) cerr<<zhi[i].first<<' '<<upper_bound(all.begin(),all.end(),zhi[i].second.first)-all.begin()<<' '<<upper_bound(all.begin(),all.end(),zhi[i].second.second)-all.begin()<<endl;
			else cerr<<zhi[i].first<<' '<<upper_bound(all.begin(),all.end(),zhi[i].second.first)-all.begin()<<' '<<zhi[i].second.second<<endl;
	}*/
	for (i=0;i<zhi.size();i++)
	{
		if (zhi[i].first==1)
		{
			sum.add(upper_bound(all.begin(),all.end(),zhi[i].second.first)-all.begin(),zhi[i].second.second);
		}
		else
		{
			printf("%d\n",sum.query(upper_bound(all.begin(),all.end(),zhi[i].second.second)-all.begin())-sum.query(upper_bound(all.begin(),all.end(),zhi[i].second.first)-all.begin()));
		}
	}
	return 0;
}