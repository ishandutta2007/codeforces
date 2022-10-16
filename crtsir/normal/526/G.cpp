#include<bits/stdc++.h>
using namespace std;
int n,q;
vector<int>v[100003],g[100003];
pair<int,int>farthest(int x,int p=-1,int dep=0){
	pair<int,int>ret={dep,x};
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=p)
			ret=max(farthest(v[x][i],x,dep+g[x][i]),ret);
	return ret;
}
struct tr{
	int col[100003],val[100003],idx[100003],pa[17][100003],mx[100003],ans[200003],ord[100003],dept[100003];
	pair<int,int>dfs(int x,int p,int dep){
		dept[x]=dep;
		pa[0][x]=p;
		pair<int,int>ret={0,x};
		for(int i=0;i<v[x].size();i++)
			if(v[x][i]!=p){
				pair<int,int>tmp=dfs(v[x][i],x,dep+g[x][i]);
				tmp.first+=g[x][i];
				if(tmp>ret)
					swap(tmp,ret);
				val[tmp.second]=tmp.first;
			}
		mx[x]=ret.first;
		col[x]=ret.second;
		return ret;
	}
	void init(int rt){
		memset(pa,-1,sizeof(pa));
		pair<int,int>tmp=dfs(rt,-1,0);
		val[tmp.second]=tmp.first;
		vector<pair<int,int> >V;
		for(int i=0;i<n;i++)
			V.push_back({-val[i],i});
		sort(V.begin(),V.end());
		for(int i=0;i<n;i++){
			idx[i]=V[i].second;
			ord[idx[i]]=i;;
		}
		for(int i=1;i<17;i++)
			for(int j=0;j<n;j++)
				if(pa[i-1][j]!=-1)
					pa[i][j]=pa[i-1][pa[i-1][j]];
				else
					pa[i][j]=-1;
		ans[0]=val[idx[0]];
		for(int i=1;i<n;i++)
			ans[i]=ans[i-1]+val[idx[i]];
	}
	int query(int x,int y){
		if(y*2>=n+1)return ans[n-1];
		int ans1=0;
		if(y>1)ans1=ans[2*y-3];
		int nw=x;
		for(int i=16;i>=0;i--)
			if(pa[i][nw]!=-1)
				if(ord[col[pa[i][nw]]]>2*y-3)
					nw=pa[i][nw];
		if(pa[0][nw]!=-1&&ord[col[nw]]>2*y-3)
			nw=pa[0][nw];
		if(nw!=x)
			ans1+=dept[x]+mx[x]-dept[nw];
		int ans2=ans[2*y-2];
		nw=x;
		for(int i=16;i>=0;i--)
			if(pa[i][nw]!=-1)
				if(ord[col[pa[i][nw]]]>2*y-2)
					nw=pa[i][nw];
		if(pa[0][nw]!=-1&&ord[col[nw]]>2*y-2)
			nw=pa[0][nw];
		ans2+=mx[x]-mx[nw]+dept[x]-dept[nw];
		return max(ans1,ans2);
	}
}q1,q2;
int lstans;
int main(){
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
		g[x].push_back(w);
		g[y].push_back(w);
	}
	q1.init(farthest(0).second);
	q2.init(farthest(farthest(0).second).second);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+lstans-1)%n;
		y=(y+lstans-1)%n+1;
		lstans=max(q1.query(x,y),q2.query(x,y));
		printf("%d\n",lstans);
	}
}