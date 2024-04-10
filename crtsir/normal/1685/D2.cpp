#include<bits/stdc++.h>
using namespace std;
int T,n,p[203],fa[203],vis[203],ip[203];
int ls[203],nx[203],L[203],R[203];
int fnd(int x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
void add(int x,int y){
	nx[x]=y;ls[y]=x;
	if(x<y)for(int i=x;i<y;i++)R[i]++;
	else for(int i=x;i>y;i--)L[i]++;
}
void del(int x,int y){
	nx[x]=-1;ls[y]=-1;
	if(x<y)for(int i=x;i<y;i++)R[i]--;
	else for(int i=x;i>y;i--)L[i]--;
}vector<int>v[203];
void dfs(int x){vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);}
bool check(){
	for(int i=0;i<n;i++){
		if(L[i]||R[i])
			if(ls[i]==i)
				return 0;
		if(ls[i]==-1&&nx[i]==-1&&L[i]&&R[i])
			return 0;
	}int cnt=0;
	for(int i=0;i<n;i++)
		vis[i]=0,v[i].clear();
	for(int i=1;i<n;i++)
		if(L[i]||R[i-1])
			cnt++,
			v[fa[i]].push_back(fa[i-1]),
			v[fa[i-1]].push_back(fa[i]);
	for(int i=0;i<n;i++)
		if(fa[i]==i)
			if(!vis[i])
				dfs(i);
			else
				cnt--;
	if(cnt)return 0;
	for(int i=0;i<n;i++)
		v[i].clear(),vis[i]=0;
	for(int i=1;i<n;i++)
		if((ls[i-1]==-1||nx[i-1]==-1||ls[i-1]>i-1||nx[i-1]>i-1)&&(ls[i]==-1||nx[i]==-1||ls[i]<i||nx[i]<i))
			v[fa[i]].push_back(fa[i-1]),
			v[fa[i-1]].push_back(fa[i]);
	for(int i=0;i<n;i++)
		if(fa[i]==i&&!vis[i])
			dfs(i),cnt++;
	return cnt<2;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>p[i],p[i]--,fa[i]=i,ip[p[i]]=i;
		for(int i=0;i<n;i++)
			fa[fnd(i)]=fnd(p[i]);
		for(int i=0;i<n;i++)
			fa[i]=fnd(fa[i]);
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(ls,-1,sizeof(ls));
		memset(nx,-1,sizeof(nx));
		cout<<1<<' ';int lst=0;
		for(int T=1;T<n;T++){
			for(int i=0;i<n;i++)
				if(ls[p[i]]==-1){
					add(lst,p[i]);
					if(check()){
						lst=i;
						break;
					}
					del(lst,p[i]);
				}
			cout<<lst+1<<' ';
		}cout<<'\n';
	}
}