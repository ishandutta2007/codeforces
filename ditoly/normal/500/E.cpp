#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
int l[MN+5],r[MN+5],c[MN*2+5],cn,s[MN*2+5],ans[MN+5];
set<int> st;
vector< pair<int,int> > v[MN+5];
inline int add(int x,int z){for(;x<=MN*2;x+=x&-x)s[x]+=z;}
inline int sum(int x){int r=0;for(;x;x-=x&-x)r+=s[x];return r;}
inline int f(int x){return lower_bound(c+1,c+cn+1,x)-c;}
int main()
{
	int n=read(),m,i,x;
	for(i=1;i<=n;++i)c[++cn]=l[i]=read(),c[++cn]=r[i]=l[i]+read();
	sort(c+1,c+cn+1);cn=unique(c+1,c+cn+1)-c-1;
	for(i=1;i<=cn;++i)st.insert(i);
	for(m=read(),i=1;i<=m;++i)x=read(),v[x].push_back(make_pair(i,read()));
	for(i=n;i;--i)
	{
		l[i]=f(l[i]);r[i]=f(r[i]);
		for(set<int>::iterator it=st.lower_bound(l[i]);*it<r[i];)
			add(*it,c[*it+1]-c[*it]),st.erase(it++);
		for(x=0;x<v[i].size();++x)
			ans[v[i][x].first]=c[l[v[i][x].second]]-c[l[i]]-sum(l[v[i][x].second]-1);
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]);
}