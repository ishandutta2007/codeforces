#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-8;
const double PI = acos(-1.0);

struct A1
{
	int num,l,r;
	A1(int _num,int _l,int _r):
		num(_num),
		l(_l),
		r(_r)
		{}
};

bool cmp(const A1& a,const A1& b)
{
	return (a.num<b.num || (a.num==b.num && a.l<b.l));
}

inline bool bit(int i,int x)
{
	return ((x>>i)&1);
}

int n,m,k;
vector<A1> v,g,nv,ng;
vector<int> sv,sg;

int summa(const vector<A1>& a,int vl,int vr)
{
	int ans=0;
	int r=-1;
	for (int i=vl; i<=vr; i++)
		if (a[i].r>r)
		{
			int l=max(r+1,a[i].l);
			ans=ans+a[i].r-l+1;
			r=a[i].r;
		}
	return ans;
}

void getAns(const vector<A1>& a,int vl,int vr,int s,int& a1,int& a2)
{
	a1=0;
	int cnt=0,r=-1;
	for (int i=vl; i<=vr; i++)
	{
		if (a[i].r<=r)continue;
		if (a[i].l>r)
		{
			if (cnt+a[i].l-r-1>=s)break;
			cnt+=a[i].l-r-1;
		}
		r=a[i].r;
	}
	if (cnt<s)
		r += s-cnt;
	a2=r;
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin >> n >> m >> k;
	for (int i=0; i<k; i++)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1==x2)
			g.push_back(A1(x1,min(y1,y2),max(y1,y2)-1));
		if (y1==y2)
			v.push_back(A1(y1,min(x1,x2),max(x1,x2)-1));
	}
	sort(g.begin(),g.end(),cmp);
	sort(v.begin(),v.end(),cmp);
	
	int tmp1,tmp2;
	tmp1=-1;
	for (int i=0; i<v.size(); i++)
		if (tmp1!=v[i].num)
		{
			if (tmp1!=-1)
				nv[nv.size()-1].r=i-1;
			tmp1=v[i].num;
			nv.push_back(A1(tmp1,i,0));
		}
	if (nv.size()!=0)
		nv[nv.size()-1].r=v.size()-1;

	tmp1=-1;
	for (int i=0; i<g.size(); i++)
		if (tmp1!=g[i].num)
		{
			if (tmp1!=-1)
				ng[ng.size()-1].r=i-1;
			tmp1=g[i].num;
			ng.push_back(A1(tmp1,i,0));
		}
	if (ng.size()!=0)
		ng[ng.size()-1].r=g.size()-1;

	sv.resize(nv.size());
	sg.resize(ng.size());
	for (int i=0; i<nv.size(); i++)
		sv[i]=(n-summa(v,nv[i].l,nv[i].r));
	for (int i=0; i<ng.size(); i++)
		sg[i]=(m-summa(g,ng[i].l,ng[i].r));

	int ans=0;
	tmp1=m-nv.size()-1;
	if (tmp1%2)ans ^= n;
	tmp1=n-ng.size()-1;
	if (tmp1%2)ans ^= m;
	for (int i=0; i<nv.size(); i++)
		ans ^= sv[i];
	for (int i=0; i<ng.size(); i++)
		ans ^= sg[i];
	if (!ans)
	{
		cout << "SECOND" << endl;
		return 0;
	}
	cout << "FIRST" << endl;
	
	for (int i=0; i<nv.size(); i++)
		if ((ans^sv[i])<sv[i])
		{
			getAns(v,nv[i].l,nv[i].r,sv[i]-(ans^sv[i]),tmp1,tmp2);
			cout << tmp1 << " " << nv[i].num << " " << tmp2+1 << " " << nv[i].num << endl;
			return 0;
		}
	for (int i=0; i<ng.size(); i++)
		if ((ans^sg[i])<sg[i])
		{
			getAns(g,ng[i].l,ng[i].r,sg[i]-(ans^sg[i]),tmp1,tmp2);
			cout << ng[i].num << " " << tmp1 << " " << ng[i].num << " " << tmp2+1 << endl;
			return 0;
		}
	int num;
	if (m-1>nv.size() && (ans^n)<n)
	{
		int num=nv.size()+1;
		for (int i=1; i<=nv.size(); i++)
			if (nv[i-1].num!=i)
			{
				num=i;
				break;
			}
		cout << 0 << " " << num << " " << n-(ans^n) << " " << num << endl;
	}else
	{
		int num=ng.size()+1;
		for (int i=1; i<=ng.size(); i++)
			if (ng[i-1].num!=i)
			{
				num=i;
				break;
			}
		cout << num << " " << 0 << " " << num << " " << m-(ans^m) << endl;
	}
	return 0;
}