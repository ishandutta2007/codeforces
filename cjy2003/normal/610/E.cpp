#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m,k;
char a[200020],t[20];
struct Data
{
	int l,r,c;
	friend operator < (Data a,Data b){return a.l<b.l;}
};
set<Data>s;
int cnt[10][10];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	scanf("%s",a+1);
	for(int i=1;i<=n;++i)s.insert(Data{i,i,a[i]-'a'});
	for(int i=1;i<n;++i)++cnt[a[i]-'a'][a[i+1]-'a'];
	int c,x,y;
	char ch;
	while(m--)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d %d %c",&x,&y,&ch);ch-='a';
			auto it=prev(s.upper_bound(Data{x,0,0}));
			Data l,r;
			l=*it,l.r=x-1;
			if(it!=s.begin())--cnt[prev(it)->c][it->c];
			while(it!=s.end()&&it->l<=y)
			{
				cnt[it->c][it->c]-=it->r-it->l;
				if(next(it)!=s.end())--cnt[it->c][next(it)->c];
				r=*it;it=next(it);s.erase(prev(it));
			}
			r.l=y+1;
			if(l.l<=l.r)
			{
				it=s.insert(l).first;
				cnt[it->c][it->c]+=it->r-it->l;
				if(it!=s.begin())++cnt[prev(it)->c][it->c];
			}
			if(r.l<=r.r)
			{
				it=s.insert(r).first;
				cnt[it->c][it->c]+=it->r-it->l;
				if(next(it)!=s.end())++cnt[it->c][next(it)->c];
			}
			it=s.insert(Data{x,y,ch}).first;
			cnt[it->c][it->c]+=it->r-it->l;
			if(it!=s.begin())++cnt[prev(it)->c][it->c];
			if(next(it)!=s.end())++cnt[it->c][next(it)->c];
			// for(auto p:s)printf("%d %d %d\n",p.l,p.r,p.c);
			// for(int i=0;i<k;++i)
			// 	for(int j=0;j<k;++j)
			// 		printf("%d%c",cnt[i][j],j==k-1?'\n':' ');
			// printf("\n");
		}
		else
		{
			scanf("%s",t+1);
			for(int i=1;i<=k;++i)t[i]-='a';
			int ans=0;
			for(int i=1;i<=k;++i)
				for(int j=1;j<=i;++j)
					ans+=cnt[t[i]][t[j]];
			printf("%d\n",ans+1);
		}
	}
	return 0;
}