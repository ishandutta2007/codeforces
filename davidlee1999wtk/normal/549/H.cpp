#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
inline double Min(double a,double c,double mid)
{
	double t1;
	t1=min(min((a+mid)*(c+mid),(a-mid)*(c+mid)),min((a+mid)*(c-mid),(a-mid)*(c-mid)));
	return t1;
}

inline double Max(double a,double c,double mid)
{
	double t1;
	t1=max(max((a+mid)*(c+mid),(a-mid)*(c+mid)),max((a+mid)*(c-mid),(a-mid)*(c-mid)));
	return t1;
}

int main()
{
	double ta,tb,tc,td;
	long double a,b,c,d,l,r,mid,t1,t2;
	int i;
	cin>>ta>>tb>>tc>>td;
	a=ta;
	b=tb;
	c=tc;
	d=td;
	swap(c,d);
	l=0,r=1e9;
	if(a*c>b*d)
	{
		for(i=1;i<=80;i++)
		{
			mid=(l+r)/2;
			t1=min(min((a+mid)*(c+mid),(a-mid)*(c+mid)),min((a+mid)*(c-mid),(a-mid)*(c-mid)));
			t2=Max(b,d,mid);
			if(t2>t1)
				r=mid;
			else l=mid;
		}
	}
	else
	{
		for(i=1;i<=80;i++)
		{
			mid=(l+r)/2;
			t1=Max(a,c,mid);
			t2=Min(b,d,mid);
			if(t2<t1)
				r=mid;
			else l=mid;
		}
	}
	//debug(Max(a,c,0.2));
	//debug(Min(a,c,0.2));
	printf("%.10f\n",(double)l);
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);