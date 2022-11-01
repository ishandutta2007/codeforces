#include<bits/stdc++.h>
using namespace std;
const int N = 500000+100;
struct edge{
	int x,y,w,id;
}e[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int n,m,q,tot;
int Map2[N],Map[N];
vector<int> v[N];
vector<int> sta[N];
int fa[N],Rank[N];
int find(int x)
{
	return fa[x]==x? x: find(fa[x]);
}
bool ans[N];
int flag[N],pos[N];
edge qq[N*2];
int cnt;
bool cmp2(int a,int b)
{
	return Map2[a]<Map2[b];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		e[i].id = i;
	}
	sort(e+1,e+m+1,cmp);
	for(int i =1;i<=m;i++)
	{
		if(i==1 || e[i].w!=e[i-1].w)
		{
			 ++tot;
		}
		Map[e[i].id] = tot;
		Map2[e[i].id] = i;
	}
	scanf("%d",&q);
	for(int i = 1;i<=q;i++)
	{
		int sz,id;
		scanf("%d",&sz);
		for(int j =0;j<sz;j++)
		{
			scanf("%d",&id);
			v[i].push_back(id);
			sta[Map[id]].push_back(i);
		}
		sort(v[i].begin(),v[i].end(),cmp2);
	}
	for(int i= 1;i<=n;i++) fa[i] = i;
	int tmp1,tmp2;
	
	for(int i = 1;i<=q;i++) ans[i] = true,pos[i] = 0;
	
	for(int i =1,j,now = 1;i<=m;i =j,now++)
	{ 
	
		for(int j  = 0;j<sta[now].size();j++) if(flag[sta[now][j]]!=now)
		{	
			flag[sta[now][j]] = now;
			int t = sta[now][j],t2;
		
			cnt = 0;
			while(pos[t]<v[t].size() && Map[v[t][pos[t]]]==now)
			{
				t2 = Map2[v[t][pos[t]]];
				tmp1 = find(e[t2].x);
				tmp2 = find(e[t2].y);
			
				if(tmp1!=tmp2)
				{
					cnt++;
					qq[cnt].x = tmp1,qq[cnt].y = fa[tmp1],qq[cnt].w = Rank[tmp1];
					
					cnt++;
					qq[cnt].x = tmp2,qq[cnt].y = fa[tmp2],qq[cnt].w = Rank[tmp2];
					
					if(Rank[tmp1]>Rank[tmp2]) swap(tmp1,tmp2);
					fa[tmp1] = tmp2;
					if(Rank[tmp1]==Rank[tmp2]) Rank[tmp2]++;
					
				} 
				else ans[t] =false;
				pos[t]++;
			}
			for(int k = 1;k<=cnt;k++){
				tmp1 = qq[k].x;
				fa[tmp1] = qq[k].y;
				Rank[tmp1] = qq[k].w;
			}
		}
		for(j=i;j<=m && e[j].w==e[i].w;j++)
		{
			tmp1 = find(e[j].x);
			tmp2 = find(e[j].y);
			if(tmp1!=tmp2)
			{
				if(Rank[tmp1]>Rank[tmp2]) swap(tmp1,tmp2);
				fa[tmp1] = tmp2;
				if(Rank[tmp1]==Rank[tmp2]) Rank[tmp2]++;
			}
		}
	}
	for(int i =1;i<=q;i++) 
	{
		if(ans[i]) puts("YES");
		else puts("NO");
	}
	return 0;
}