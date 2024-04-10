#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,m,K;
bool deg[300004];
int nxt[300004],pre[300004],len[300004];
bool bn[300004],ins[300004];
pair<bool,int> dfs(int x){
	if(bn[x]||len[x])return {bn[x],len[x]};
	ins[x]=1;
	int c=nxt[x];
	if(c==0)len[x]=1;
	else if(ins[c])bn[x]=1;
	else{
		auto [g,f]=dfs(c);
		if(g)bn[x]=1;
		else len[x]=f+1;
	}
	ins[x]=0;
	return {bn[x],len[x]};
}
int cnt[300004];
vector<pair<int,int> >v;
int f[300004];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++){
		int N,lst,c;scanf("%d",&N);
		scanf("%d",&lst);
		for(int j=1;j<N;j++){
			scanf("%d",&c),deg[c]=1;
			if(nxt[lst]!=0&&nxt[lst]!=c)bn[lst]=1;
			if(pre[c]!=0&&pre[c]!=lst)bn[c]=1;
			nxt[lst]=c,pre[c]=lst,lst=c;
		}
	}
	for(int i=1;i<=K;i++)if(!bn[i]&&len[i]==0&&!deg[i]){
		dfs(i);
		cnt[len[i]]++;
	}
	for(int i=1;i<=m;i++)if(cnt[i]>0)v.push_back({i,cnt[i]});
	f[0]=1;
	for(int i=0;i<m;i++)if(f[i])
		for(auto x:v)if(x.first+i<=m)
			(f[x.first+i]+=(ll)f[i]*x.second%M)%=M;
	printf("%d",f[m]);
}