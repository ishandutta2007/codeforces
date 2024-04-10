#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=305;
typedef pair<int,int> pii;
#define mk make_pair

set<pii> st;//1:hang -1lie
int n,m;
int bl[N*N],a[N][N],vis[N][N];
int ans[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<=m;j++) mx=max(mx,a[i][j]);
		st.insert(mk(mx,1));
		bl[mx]=1;
	}
	for(int j=1;j<=m;j++)
	{
		int mx=0;
		for(int i=1;i<=n;i++) mx=max(mx,a[i][j]);
		st.insert(mk(mx,-1));
		bl[mx]=1;
	}
	int hang=1,lie=1,now=1;
	while(!st.empty())
	{
		pii u=*st.begin(); st.erase(u);
		//cout<<u.first<<" "<<u.second<<endl;
		pii tmp=*st.begin(); 
		if(tmp.first==u.first)
		{
			st.erase(tmp);
			u.second=2;
		}
		vector<int> v;
		ans[hang][lie]=u.first;
		if(u.second==1)//hang
		{
			v.clear();
			for(int i=lie+1;i<=m;i++) 
			{
				while(bl[now]) now++;
				v.push_back(now); now++;
			}
			for(int i=m,j=0;i>=lie+1;i--)
			{
				ans[hang][i]=v[j]; j++;
			}
			hang++;
		}
		else if(u.second==-1)//lie
		{
			v.clear();
			for(int i=hang+1;i<=n;i++)
			{
				while(bl[now]) now++;
				v.push_back(now); now++;
			}
			for(int i=n,j=0;i>=hang+1;i--)
			{
				ans[i][lie]=v[j]; j++;
			}
			lie++;
		}
		else
		{
			v.clear();
			for(int i=lie+1;i<=m;i++) 
			{
				while(bl[now]) now++;
				v.push_back(now); now++;
			}
			for(int i=m,j=0;i>=lie+1;i--)
			{
				ans[hang][i]=v[j]; j++;
			}
			v.clear();
			for(int i=hang+1;i<=n;i++)
			{
				while(bl[now]) now++;
				v.push_back(now); now++;
			}
			for(int i=n,j=0;i>=hang+1;i--)
			{
				ans[i][lie]=v[j]; j++;
			}
			lie++; hang++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}