#include<bits/stdc++.h>
using namespace std;
const int $=4e5,$$=1e7;
int n,lg[$],ST[19][$],dfn[$],tim,dep[$],rt[$],lc[$$],rc[$$],lp[$$],rp[$$],Pc;
long long ans=2,sum[$$]; char s[$];
int Min(int x,int y){
	if(!x||!y)return 0; if(x>y)swap(x,y); int B=lg[y-x+1];
	return min(ST[B][x],ST[B][y-(1<<B)+1]);
}
void up(int p){
	lp[p]=lp[lc[p]?lc[p]:rc[p]]; rp[p]=rp[rc[p]?rc[p]:lc[p]];
	sum[p]=sum[lc[p]]+sum[rc[p]]-Min(rp[lc[p]],lp[rc[p]]);
}
#define md (L+R>>1)
void ins(int&p,int x,int v,int L=1,int R=tim){
	if(!p)p=++Pc; if(L==R){lp[p]=rp[p]=x;sum[p]=v;return;}
	if(x>md)ins(rc[p],x,v,md+1,R);else ins(lc[p],x,v,L,md); up(p);
}
int merge(int a,int b){
	if(!a||!b)return a|b; int o=++Pc;
	lc[o]=merge(lc[a],lc[b]); rc[o]=merge(rc[a],rc[b]); up(o);return o;
}
struct SAM{
	int pc,lst,c[26][$],f[$],len[$],ip[$]; vector<int>E[$];
	SAM(){pc=lst=1;}
	void ins(int C){
		int p=lst,P=lst=++pc,q,Q; dep[P]=len[P]=len[p]+1; ip[len[P]]=P;
		for(;p&&!c[C][p];p=f[p])c[C][p]=P;
		if(!p){f[P]=1;return;}
		if(len[q=c[C][p]]==len[p]+1){f[P]=q;return;}
		Q=++pc; dep[Q]=len[Q]=len[p]+1; f[Q]=f[q]; f[q]=f[P]=Q;
		for(int i=0;i<26;++i)c[i][Q]=c[i][q];
		for(;c[C][p]==q;p=f[p])c[C][p]=Q;
	}
	void tree(){for(int i=2;i<=pc;++i)E[f[i]].push_back(i);}
	void dfs(int p){ST[0][dfn[p]=++tim]=dep[p]; for(int y:E[p])dfs(y),ST[0][++tim]=dep[p];}
	void buildST(){dfs(1); for(int i=1;i<19;++i)for(int j=1;j+(1<<i)-1<=tim;++j)ST[i][j]=min(ST[i-1][j],ST[i-1][j+(1<<i-1)]);}
	void DFS(int p){for(int y:E[p])DFS(y),rt[p]=merge(rt[p],rt[y]);}
	void cal(){DFS(1); for(int i=2;i<=pc;++i)ans+=sum[rt[i]]*(len[i]-len[f[i]]);}
}S,R;
int main(){
	for(int i=2;i<$;++i)lg[i]=lg[i>>1]+1;
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;++i)S.ins(s[i]-97),ans+=(i-S.len[S.f[S.lst]])*(1+(i!=n));
	for(int i=n;i;--i)R.ins(s[i]-97),ans+=(i!=1)*(n-i+1-R.len[R.f[R.lst]]);
	S.tree(); R.tree(); R.buildST();
	for(int i=1;i<n-1;++i)ins(rt[S.ip[i]],dfn[R.ip[n-i-1]],n-i-1);
	S.cal(); printf("%lld",ans);
}