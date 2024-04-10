#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
set<int>l,r;
char s[100010];
int n,cntl,cntr,ans=0x3f3f3f3f,pt[100010],cur[100010];
inline char findbg()
{
	if(!l.size())return 'R';
	else if(!r.size())return 'L';
	else return *l.begin()<*r.begin()?'L':'R';
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)s[i]=='L'?++cntl:++cntr;
	if(cntl>=cntr)
	{
		for(int i=1;i<=n;++i)
			if(s[i]=='L')l.insert(i);
			else r.insert(i);
		int p=0,op=0,cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(op)
			{
				auto it=r.lower_bound(p);
				if(it!=r.end())
				{
					if(findbg()=='R'&&l.lower_bound(*it)==l.end()&&*r.begin()<p)p=*r.begin(),++cnt;
					else p=*it;
				}
				else p=*r.begin(),++cnt;
				r.erase(p);
			}
			else
			{
				auto it=l.lower_bound(p);
				if(it!=l.end())
				{
					if(findbg()=='L'&&r.lower_bound(*it)==r.end()&&*l.begin()<p)p=*l.begin(),++cnt;
					else p=*it;
				}
				else p=*l.begin(),++cnt;
				l.erase(p);
			}
			op^=1;cur[i]=p;
		}
		if(cnt<ans)ans=cnt,memcpy(pt+1,cur+1,n<<2);
	}
	if(cntr>=cntl)
	{
		for(int i=1;i<=n;++i)
			if(s[i]=='R')l.insert(i);
			else r.insert(i);
		int p=0,op=0,cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(op)
			{
				auto it=r.lower_bound(p);
				if(it!=r.end())
				{
					if(findbg()=='R'&&l.lower_bound(*it)==l.end()&&*r.begin()<p)p=*r.begin(),++cnt;
					else p=*it;
				}
				else p=*r.begin(),++cnt;
				r.erase(p);
			}
			else
			{
				auto it=l.lower_bound(p);
				if(it!=l.end())
				{
					if(findbg()=='L'&&r.lower_bound(*it)==r.end()&&*l.begin()<p)p=*l.begin(),++cnt;
					else p=*it;
				}
				else p=*l.begin(),++cnt;
				l.erase(p);
			}
			op^=1;cur[i]=p;
		}
		if(cnt<ans)ans=cnt,memcpy(pt+1,cur+1,n<<2);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)printf("%d ",pt[i]);
	return 0;
}