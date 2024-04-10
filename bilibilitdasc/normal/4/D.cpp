#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
struct pnt{
	int ord,h,w;
	bool operator<(pnt x)
	{
		if(h!=x.h) return h<x.h;
		return w>x.w;
	}
};
vector<pnt> l;
int ml[5005];
int prevv[5005];
int h1,w1,n;
int hh,ww;
pnt ppp;
stack<int> a1;
#define o(i) l[i].ord
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>h1>>w1;
	for(int i=1;i<=n;i++)
	{
		cin>>hh>>ww;
		if(hh>h1&&ww>w1)
		{
			ppp.ord=i;
			ppp.h=hh;
			ppp.w=ww;
			l.push_back(ppp);
		}
	}
	sort(l.begin(),l.end());
	int mxans=0,mxend=0;
	for(int i=0;i<l.size();i++)
	{
		int tmp=0;
		for(int j=0;j<i;j++)
		{
			if(l[j].w<l[i].w&&ml[j]>tmp)
			{
				tmp=ml[j];
				prevv[o(i)]=o(j);
			}
		}
		ml[i]=1+tmp;
		if(ml[i]>mxans)
		{
			mxans=ml[i];
			mxend=o(i);
		}
	}
	cout<<mxans<<endl;
	while(mxend!=0)
	{
		a1.push(mxend);
		mxend=prevv[mxend];
	}
	while(!a1.empty())
	{
		cout<<a1.top();
		a1.pop();
		if(!a1.empty())
		{
			cout<<' ';
		}
		else
		{
			cout<<endl;
		}
	}
	return 0;
}