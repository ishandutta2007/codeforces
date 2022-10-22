#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int t,n,l,a[N],aa[N],bb[N];
double ans;

struct Node
{
	int len,id;
};

signed main()
{
	t=read();
	while(t--)
	{
		n=read();l=read();
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			aa[i]=a[i];
			bb[i]=l-a[i];
		}
		aa[n+1]=l;
		bb[n+1]=l;
		sort(aa+1,aa+2+n);
		sort(bb+1,bb+2+n);
		double A=0,B=l,sa=1,sb=1;
		int I=1,J=1;
		ans=0;
		for(int i=1;i<=n*2+2;++i)
		{
			Node tmp;
			if(fabs(A-aa[I])/sa<=fabs(B-(l-bb[J]))/sb)
				tmp=(Node){aa[I],1},I++;
			else tmp=(Node){bb[J],2},J++;
			double tA=A,tB=B,ttt=0;
			if(tmp.id==1)
			{
				tA=tmp.len;
				ttt=fabs(tA-A+0.0)/sa;
				tB-=sb*ttt;
			}
			else
			{
				tB=l-tmp.len;
				ttt=fabs(tB-B+0.0)/sb;
				tA+=sa*ttt;
			}
			if(tA>=tB)
			{
				ans+=fabs(B-A+0.0)/(sa+sb);
				break;
			}
			if(tmp.id==1) sa++;
			else sb++;
			A=tA,B=tB;
			ans+=ttt;
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}