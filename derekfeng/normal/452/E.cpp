#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
typedef long long ll;
struct SAM{
	int lst,cnt;
	int nxt[600004][26],len[600004],fa[600004],sz[3][1000004];
	void init(int N){
		N*=2;
		lst=cnt=1;
		for(int i=0;i<=N;i++){
			memset(nxt[i],0,sizeof(nxt[i]));
			len[i]=fa[i]=sz[0][i]=sz[1][i]=sz[2][i]=0;
		}
	}
	void add(int c,int r){
		int p=lst;int np=lst=++cnt;sz[r][np]++;
		len[np]=len[p]+1;
		for(;p&&!nxt[p][c];p=fa[p])nxt[p][c]=np;
		if(!p)fa[np]=1;
		else{
			int q=nxt[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else{
				int nq=++cnt;
				for(int i=0;i<26;i++)nxt[nq][i]=nxt[q][i];
				fa[nq]=fa[q];
				len[nq]=len[p]+1,fa[q]=fa[np]=nq;
				for(;p&&nxt[p][c]==q;p=fa[p])nxt[p][c]=nq; 
			}
		}
	}
	int num,head[1000004],prev[1000004],edg[1000004];
	void initg(int N){
		for(int i=1;i<=N;i++)head[i]=0;
		num=0;
	}
	void adde(int u,int v){
		++num,edg[num]=v,prev[num]=head[u],head[u]=num;
	}
	void builtg(){
		initg(cnt);
		for(int i=2;i<=cnt;i++)adde(fa[i],i);
	}
}Sam;
ll ss[300005];
void dfs(int x){
	for(int i=Sam.head[x];i;i=Sam.prev[i]){
		int y=Sam.edg[i];
		dfs(y);for(int j=0;j<3;j++)Sam.sz[j][x]+=Sam.sz[j][y];
	}
	ll ad=(ll)Sam.sz[0][x]*Sam.sz[1][x]%Mod*Sam.sz[2][x]%Mod;
	if(x>1)ss[Sam.len[Sam.fa[x]]+1]+=ad,ss[Sam.len[x]+1]-=ad;
}
int L=3e5,M;
char str[3][300005];
int main(){
	Sam.init(L); 
	for(int i=0;i<3;i++){
		scanf("%s",str[i]+1),M=strlen(str[i]+1);L=min(L,M);
		Sam.lst=1;
		for(int j=1;j<=M;j++)Sam.add(str[i][j]-'a',i);
	}
	Sam.builtg();
	dfs(1);
	for(int i=1;i<=L;i++)ss[i]+=ss[i-1];
	for(int i=1;i<=L;i++)printf("%d ",ss[i]%Mod);
}