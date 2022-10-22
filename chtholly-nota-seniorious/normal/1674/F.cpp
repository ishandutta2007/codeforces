#include "bits/stdc++.h"
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
template<typename typC> struct bit
{
	vector<typC> a;
	int n;
	bit(){}
	bit(int nn):n(nn),a(nn+1){}
	template<typename T> bit(int nn,T *b):n(nn),a(nn+1)
	{
		for (int i=1;i<=n;i++) a[i]=b[i];
		for (int i=1;i<=n;i++) if (i+(i&-i)<=n) a[i+(i&-i)]+=a[i];
	}
	void add(int x,typC y)
	{
		//cerr<<"add "<<x<<" by "<<y<<endl;
		assert(1<=x&&x<=n);
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	typC sum(int x)
	{
		//cerr<<"sum "<<x;
		assert(0<=x&&x<=n);
		typC r=a[x];
		while (x^=x&-x) r+=a[x];
		//cerr<<"= "<<r<<endl;
		return r;
	}
	typC sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
const int N=1e6+5;
int a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,q,i,j,cur=0;
	cin>>n>>m>>q;
	for (i=0;i<n;i++)
	{
		string s;
		cin>>s;
		for (j=0;j<m;j++) a[i+j*n+1]=s[j]=='*';
	}
	m*=n;
	cur=accumulate(a+1,a+m+1,0);
	bit<int> s(m,a);
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		x+=n*(y-1);
		if (a[x]) s.add(x,-1),--cur; else s.add(x,1),++cur;
		a[x]^=1;
		cout<<cur-s.sum(cur)<<'\n';
	}
}