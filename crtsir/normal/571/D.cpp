#include<bits/stdc++.h>
using namespace std;
namespace Military{
	int fa[1000003],N,ans[1000003],pa[1000003],ls[1000003],rs[1000003];
	bool vis[1000003];
	int fnd1(int x){if(pa[x]!=x)pa[x]=fnd1(pa[x]);return pa[x];} 
	int fnd2(int x){if(fa[x]!=x)fa[x]=fnd2(fa[x]);return fa[x];} 
	void init(int n){
		N=n;
		for(int i=0;i<1000003;i++)
			fa[i]=i,pa[i]=i;
		for(int i=0;i<n;i++)
			vis[i]=1,ans[i]=0;
	}
	void merge(int a,int b){
		ls[N]=fnd1(a);rs[N]=fnd1(b);
		pa[ls[N]]=N;pa[rs[N]]=N;N++;
	}
	void reinit(int x,int p){
		fa[x]=p;
		if(vis[x])return;
		vis[x]=1;
		reinit(ls[x],p);
		reinit(rs[x],p);
	}
	void clean(int x,int y){
		x=fnd1(x);
		ans[x]=y;
		reinit(x,x);
	}
	int query(int x){
		return ans[fnd2(x)];
	}
}
namespace University{
	int pa[5][1000003],N,fa[1000003],t[1000003],its[1000003],sz[1000003],J[20];
	int sn[5][1000003];
	long long val[5][1000003];
	int fnd(int x){if(fa[x]!=x)fa[x]=fnd(fa[x]);return fa[x];} 
	void init(int n){
		N=n;
		memset(J,0,sizeof(J));
		memset(pa,-1,sizeof(pa));
		for(int i=0;i<1000003;i++)
			fa[i]=i;
		for(int i=0;i<n;i++)
			sz[i]=1;
	}
	void initquery(vector<int>v){
		for(int i=0;i<v.size();i++){
			pa[0][fnd(v[i])]=N;
			fa[fa[v[i]]]=N;
		}
		N++;
	}
	vector<int>v[1000003];
	void reinit(int n){
		for(int i=0;i<1000003;i++)
			fa[i]=i;
		for(int i=1;i<5;i++)
			for(int j=0;j<N;j++){
				bool ok=1;
				int nw=j;
				for(int k=0;k<20;k++){
					if(nw==-1){
						ok=0;
						break;
					}nw=pa[i-1][nw];
				}
				if(ok)
					pa[i][j]=nw;
				else
					pa[i][j]=-1;
			}
		for(int i=0;i<5;i++){
			for(int j=0;j<N;j++)
				v[j].clear();
			for(int j=0;j<N;j++)
				if(pa[i][j]!=-1)
					v[pa[i][j]].push_back(j);
			int l=0;
			for(int j=0;j<N;j++)
				for(int k=0;k<v[j].size();k++)
					sn[i][l++]=v[j][k];
		}N=n;
	}
	void go(int b){
		for(int i=0;i<5;i++)
			while(pa[i][sn[i][J[i]]]==N){
				if(i==0)
					val[0][sn[i][J[i]]]=b;
				else{
					int nw=sn[i][J[i]];
					while(nw!=N){
						val[i][sn[i][J[i]]]+=val[i-1][nw];
						nw=pa[i-1][nw];
					}
				}
				J[i]++;
			}
	}
	void merge(int a,int b,int c){
		a=fnd(a);b=fnd(b);
		fa[a]=N;fa[b]=N;t[N]=c;
		go(0);
		sz[N++]=sz[a]+sz[b];
	}
	void add(int a,int c){
		a=fnd(a);
		int b=sz[a];
		fa[a]=N;t[N]=c;sz[N]=b;
		go(b);
		its[N++]=b;
	}
	long long query(int a,int c){
		for(int i=4;i>=0;i--)
			while(pa[i][a]!=-1&&pa[i][a]<N&&t[pa[i][a]]<c)
				a=pa[i][a];
		long long ans=0;
		if(t[a]>=c)ans=its[a];
		for(int i=4;i>=0;i--)
			while(pa[i][a]!=-1&&pa[i][a]<N){
				ans+=val[i][a],
				a=pa[i][a];
			}
		return ans;
	}
}
int n,m;
pair<char,vector<int> >q[500003];
int main(){
	scanf("%d%d",&n,&m);
	Military::init(n);
	University::init(n);
	for(int i=0;i<m;i++){
		char C='?';
		while(!isalpha(C))C=getchar();
		vector<int>v;
		if(C=='U'||C=='M'){int a,b;scanf("%d%d",&a,&b);a--;b--;v={a,b};}
		if(C=='A'||C=='Z'||C=='Q'){int a;scanf("%d",&a);a--;v={a};}
		if(C=='U'||C=='A')
			University::initquery(v);
		q[i]={C,v};
	}University::reinit(n);
	for(int i=0;i<m;i++){
		if(q[i].first=='U')
			University::merge(q[i].second[0],q[i].second[1],i);
		if(q[i].first=='M')
			Military::merge(q[i].second[0],q[i].second[1]);
		if(q[i].first=='A')
			University::add(q[i].second[0],i);
		if(q[i].first=='Z')
			Military::clean(q[i].second[0],i);
		if(q[i].first=='Q')
			printf("%lld\n",University::query(q[i].second[0],Military::query(q[i].second[0])));
	}
}