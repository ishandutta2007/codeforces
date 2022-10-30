#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int n,q,l,r,ch[20][100005],nxt[100005],x;
vector<int>pos[100005];
vector<int>fac[100005];
vector<int>seq[100005];
multiset<int>st;
multiset<int>::iterator it;
int main()
{
	for(int i=2;i<=100000;i++)for(int j=i;j<=100000;j+=i)fac[j].push_back(i);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=0;j<fac[x].size();j++)
		{
			int v=fac[x][j];
			seq[v].push_back(i);
		}
	}
	for(int i=1;i<=n;i++)nxt[i]=n+1;
	for(int i=2;i<=100000;i++)
	{
		for(int j=0;j<(int)seq[i].size()-1;j++)
		{
			int v=seq[i][j];
			nxt[v]=min(nxt[v],seq[i][j+1]);
		}
	}
	st.insert(n+1);r=1;
	st.insert(nxt[1]);
	for(int i=1;i<=n;i++)
	{
		while(r+1<*st.begin())
		{
			r++;
			st.insert(nxt[r]);
		}
		ch[0][i]=r+1;
		it=st.find(nxt[i]);
		st.erase(it);
		//printf("@%d %d %d\n",i,r,*st.begin());
		if(r==i)
		{
			r++;
			st.insert(nxt[r]);
		}
	}
	//for(int i=1;i<=n;i++)printf("%d %d\n",nxt[i],ch[0][i]);
	ch[0][n+1]=n+1;
	for(int i=1;i<20;i++)for(int j=1;j<=n+1;j++)ch[i][j]=ch[i-1][ch[i-1][j]];
	//for(int i=1;i<=n;i++)printf("%d\n",ch[1][i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		int ans=0;
		for(int j=19;j>=0;j--)if(ch[j][l]<=r)ans+=(1<<j),l=ch[j][l];
		ans++;
		printf("%d\n",ans);
	}
	return 0;
}