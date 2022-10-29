//
//bl
// 
#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=500010;
typedef pair<int,int> pii;

int p[N],n,m,bl[N],x[N],y[N],in[N];
vector<int> ans,v[N];
queue<pii> q;

int main()
{
	int t; cin>>t;
	for(int ttt=1;ttt<=t;ttt++)
	{
		while(!q.empty()) q.pop();
		scanf("%d%d",&n,&m);
		ans.clear();
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=1;i<=n;i++) in[i]=0;
		for(int i=1;i<=n;i++) p[i]=0;
		for(int i=1;i<=n;i++) bl[i]=0;
		for(int i=1;i<=m;i++) 
		{
			scanf("%d%d",&x[i],&y[i]);
			if(p[x[i]]==y[i]) continue; 
			p[x[i]]=y[i];
			v[x[i]].push_back(y[i]);
			in[y[i]]++;
		}
		//cout<<tmpy<<" "<<tmpx<<endl;
		//for(int i=1;i<=n;i++) cout<<out[i]<<endl;
		for(int i=1;i<=n;i++) if(!in[i]) q.push(mk(i,0));
		while(!q.empty())
		{
			pii now=q.front(); q.pop();
			//cout<<now.first<<" "<<now.second<<endl;
			if(now.second==2) ans.push_back(now.first);
			for(int i=0;i<(int)v[now.first].size();i++)
			{
				int pos=v[now.first][i];
				if(now.second!=2) bl[pos]=max(bl[pos],now.second+1);
				in[pos]--;
				if(!in[pos])
				{
					if(bl[pos]) q.push(mk(pos,bl[pos]));
					else q.push(mk(pos,(now.second+1)%3));
				}
			}
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]); puts("");
		//if(ttt==3) return 0;
	}
	return 0;
}