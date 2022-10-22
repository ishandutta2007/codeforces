#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;
const int MAXN=3e5+10;
const int SQRN=sqrt(MAXN)+10;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') x=-1,c=getchar();
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,q,ton[MAXN],can[SQRN][SQRN],base,id[MAXN],a[MAXN],mem[MAXN],dfn[MAXN],tim,rnk[MAXN];
vector<int> Q[MAXN];
int main()
{
	//cout<<MAXN<<" "<<SQRN<<endl;
	//cout<<sizeof(ton)+sizeof(can)<<endl;
	n=read(),q=read();
	for(int i=1;i<=n;++i) a[i]=read(),Q[a[i]].push_back(i),rnk[i]=Q[a[i]].size()-1;
	base=sqrt(n)+1;
	for(int i=1;i<=n;++i) id[i]=(i-1)/base+1;
	for(int i=1;i<=id[n];++i)
	{
		memset(ton,0,sizeof(ton));
		for(int j=i;j<=id[n];++j)
		{
			can[i][j]=can[i][j-1];
			for(int k=(j-1)*base+1;k<=n && k<=j*base;++k)
			{
				++ton[a[k]];
				can[i][j]=max(can[i][j],ton[a[k]]);
			}
		}
	}
	while(q--)
	{
		++tim;
		int l=read(),r=read(),ans=0;
		int lid=id[l],rid=id[r];
		ans=can[lid+1][rid-1];
		for(int i=l;i<=lid*base && i<=n;++i)
		{
			while(rnk[i]+ans<Q[a[i]].size() && Q[a[i]][rnk[i]+ans]<=r) ++ans;
		}
		for(int i=(rid-1)*base+1;i<=r;++i)
		{
			while(rnk[i]-ans>=0 && Q[a[i]][rnk[i]-ans]>=l) ++ans;
		}
		int res=r-l+1-ans;
		printf("%d\n",max(1,ans-res));
	}
	return 0;
}