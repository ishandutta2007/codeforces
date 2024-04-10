#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int T,n,k;
char s[2020];
int ans[2020][2],cnt;
set<int>l,r;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		scanf("%s",s+1);
		for(int i=1;i<=n;++i)
			if(s[i]=='(')l.insert(i);
			else r.insert(i);
		cnt=0;
		for(int i=1;i<k;++i)
		{
			if(s[i*2-1]==')')
			{
				int nxtl=*l.upper_bound(i*2-1);
				swap(s[2*i-1],s[nxtl]);
				ans[++cnt][0]=2*i-1,ans[cnt][1]=nxtl;
				l.erase(nxtl),r.insert(nxtl);
			}
			if(s[i*2]=='(')
			{
				int nxtr=*r.upper_bound(2*i);
				swap(s[2*i],s[nxtr]);
				ans[++cnt][0]=2*i,ans[cnt][1]=nxtr;
				r.erase(nxtr),l.insert(nxtr);
			}
		}
		int res=n-2*k+2;res/=2;
		for(int i=2*k-1,j=1;j<=res;++i,++j)
			if(s[i]==')')
			{
				int nxtl=*l.upper_bound(i);
				swap(s[i],s[nxtl]);
				ans[++cnt][0]=i,ans[cnt][1]=nxtl;
				l.erase(nxtl),r.insert(nxtl);
			}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;++i)printf("%d %d\n",ans[i][0],ans[i][1]);
		l.clear(),r.clear();
	}
	return 0;
}