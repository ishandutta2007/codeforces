#include<cstdio>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
#define MX 1000000
#define mp(x,y) make_pair(x,y)
vector< pair<pair<int,int>,int> > v[MX+5];
long long l[MX+5],r[MX+5],s[MN+5],ans=1e18;
int main()
{
	int n,m,k,a,b,c,i,j;
	n=read();m=read();k=read();
	while(m--)a=read(),b=read(),c=read(),v[a].push_back(mp(mp(b,c),read()));
	for(i=1;i<=n;++i)s[i]=1e13;
	for(l[0]=n*1e13,i=1;i<=MX;++i)for(l[i]=l[i-1],j=0;j<v[i].size();++j)
		if(!v[i][j].first.second&&v[i][j].second<s[a=v[i][j].first.first])
			l[i]+=v[i][j].second-s[a],s[a]=v[i][j].second;
	for(i=1;i<=n;++i)s[i]=1e13;
	for(r[MX+1]=n*1e13,i=MX;i;--i)for(r[i]=r[i+1],j=0;j<v[i].size();++j)
		if(!v[i][j].first.first&&v[i][j].second<s[a=v[i][j].first.second])
			r[i]+=v[i][j].second-s[a],s[a]=v[i][j].second;
	for(i=1;i+k+1<=MX;++i)if(l[i]+r[i+k+1]<ans)ans=l[i]+r[i+k+1];
	printf("%I64d",ans<1e13?ans:-1);
}