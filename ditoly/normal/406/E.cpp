#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
vector<int> v[2];
int mx;long long s;
inline void rw(int x,long long y){x>mx?mx=x,s=y:x<mx?0:s+=y;}
int main()
{
	int n,m,i,x,a,b;
	n=read();m=read();
	while(m--)x=read(),v[x].push_back(read());
	for(x=0;x<2;++x)sort(v[x].begin(),v[x].end());
	for(x=0;x<2;++x)for(i=0;i<v[x].size();++i)
	{
		a=lower_bound(v[x^1].begin(),v[x^1].end(),v[x][i])-v[x^1].begin();
		b=upper_bound(v[x^1].begin(),v[x^1].end(),v[x][i])-v[x^1].begin();
		s+=1LL*a*(v[x^1].size()-a)+1LL*(b-a)*(b-a-1)/2+1LL*(b-a)*(v[x^1].size()-b);
	}
	if(s)return 0*printf("%I64d",s);
	for(x=0;x<2;++x)if(v[x].size())
	{
		if(v[x][0]==v[x][v[x].size()-1])
			rw(0,1LL*v[x].size()*(v[x].size()-1)*(v[x].size()-2)/6);
		else
		{
			a=upper_bound(v[x].begin(),v[x].end(),v[x][0])-v[x].begin();
			b=lower_bound(v[x].begin(),v[x].end(),v[x][v[x].size()-1])-v[x].begin();
			rw(v[x][v[x].size()-1]-v[x][0],
				1LL*a*(a-1)/2*(v[x].size()-b)+
				1LL*a*(v[x].size()-b)*(v[x].size()-b-1)/2+
				1LL*a*(b-a)*(v[x].size()-b));
		}
		for(i=0;i<v[x].size();++i)
		{
			a=lower_bound(v[x^1].begin(),v[x^1].end(),v[x][i])-v[x^1].begin();
			if(a)
			{
				b=lower_bound(v[x^1].begin(),v[x^1].end(),v[x^1][a-1])-v[x^1].begin();
				rw(n-v[x][i]+v[x^1][a-1],1LL*(a-b)*(a-b-1)/2+1LL*(a-b)*b);
			}
			if(a<v[x^1].size())
			{
				b=upper_bound(v[x^1].begin(),v[x^1].end(),v[x^1][a])-v[x^1].begin();
				rw(n-v[x^1][a]+v[x][i],1LL*(b-a)*(b-a-1)/2+1LL*(b-a)*(v[x^1].size()-b));
			}
		}
	}
	printf("%I64d",s);
}