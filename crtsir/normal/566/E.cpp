#include<bits/stdc++.h>
using namespace std;
bitset<1000>st[1003],val[1003],v2[1003],_val,tmp;
int n,idx[1003],inv[1003],cnt[1003];
bool fl=1;
bool cmp(int x,int y){
	for(int i=0;i<n;i++)
		if(st[x][i]!=st[y][i])
			return st[x][i]<st[y][i];
	return 0;
}
int m=0,N=1,lst=-1;
bool vis[1003];
vector<int>g[1003];
void DFS(int x,bitset<1000>mskx,bitset<1000>mskp){
	tmp=(mskx&mskp);
	vector<int>V;
	for(int i=0;i<n;i++)
		if(!vis[i])
			if((tmp&st[i]).count()>2){
				vis[i]=1;
				val[N]=st[i];
				g[x].push_back(N++);
				V.push_back(i);
			}
	for(int i=0;i<V.size();i++)
		DFS(g[x][i],st[V[i]],mskx);
}
bitset<1000>ttmp;
void _dfs(int x,int depth){
	if(depth==3){
		ttmp|=val[x];
		return;
	}
	for(int i=0;i<g[x].size();i++)
		_dfs(g[x][i],depth+1);
}
int ans[1003];
bool used[1003];
void dfs(int x,int p){
	for(int i=0;i<g[x].size();i++)
		if(g[g[x][i]].size()){
			bitset<1000>tttmp=(val[x]&val[g[x][i]]&val[p]);
			for(int j=0;j<n;j++)
				if(tttmp[j]&&j!=ans[x]&&j!=ans[p]&&!used[j]&&val[g[g[x][i]][0]][j]==1){
					ans[g[x][i]]=j;
					used[j]=1;
					break;
				}
			dfs(g[x][i],x);
		}
	for(int i=0;i<g[x].size();i++)
		if(!g[g[x][i]].size()){
			bitset<1000>tttmp=(val[x]&val[g[x][i]]&val[p]);
			for(int j=0;j<n;j++)
				if(tttmp[j]&&j!=ans[x]&&j!=ans[p]&&!used[j]){
					ans[g[x][i]]=j;
					used[j]=1;
					break;
				}
			dfs(g[x][i],x);
		}
}
void solve(bitset<1000>lm){//leaf mask
	for(int i=0;i<n;i++)
		if((lm&st[i])==lm)
			_val^=(st[i]^lm);
	for(int i=0;i<n;i++)
		if((lm&st[i])==lm)
			if(lm==st[i]){
				val[N]=st[i];
				vis[i]=1;
				g[N++].push_back(0);
			}else
				if((_val&st[i])==0)
					if(val[0].count()<st[i].count()){
						vis[i]=1;
						if(lst!=-1)
							vis[lst]=0;
						lst=i;
						val[0]=st[i];
					}
	DFS(0,val[0],lm);
	_dfs(0,0);
	int M=1;
	memset(ans,-1,sizeof(ans));
	bitset<1000>imp;
	for(int i=0;i<n;i++)
		if(lm[i]==0)
			imp[i]=1;
		else
			if(cnt[i]==lm.count())
				ans[M++]=i,
				used[i]=1, 
				imp[i]=1;
	imp|=ttmp; 
	for(int i=0;i<n;i++)
		if(imp[i]==0)
			if(ans[0]==-1||cnt[i]>cnt[ans[0]])
				ans[0]=i;
	used[ans[0]]=1;
	dfs(0,1);
	for(int i=0;i<n;i++)
		for(int j=0;j<g[i].size();j++)
			cout<<ans[i]+1<<' '<<ans[g[i][j]]+1<<endl;
}
bool cc(bitset<1000>st){
	for(int i=0;i<n;i++)
		if(st[i]==0)
			return 1;
	return 0;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int T,x;
		cin>>T;
		if(T!=n)
			fl=0;
		while(T--){
			cin>>x;
			x--;
			cnt[x]++;
			st[i][x]=1;
		}
		idx[i]=i;
	}
	if(fl){
		for(int i=1;i<n;i++)
			cout<<n<<' '<<i<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		int cnt=st[i].count();
		for(int j=0;j<n;j++)
			if((st[j]&st[i])==st[i])
				cnt--;
		if(cnt==0){
			solve(st[i]);
			return 0;
		}
	}
}