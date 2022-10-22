#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,rd[300004],cnt,N;
int T[300004],L[300004],R[300004],nxt[300004],pos[300004];
int b[300004],tot=1,dfn[300004],dfn1[300004];
int fa[300004],sz[300004],siz[300004],cnt1;
vector<int>g[300004];
char s[300004];
void built(int u,int l,int r){
	if(l==r-1)return;
	for(int i=l+1;i<r;){
		if(s[i]=='.')i++;
		else{
			int L=i,R=rd[i];
			int id=++tot;
			b[L]=b[R]=id;
			g[u].push_back(id),fa[id]=u;
			built(id,L,R);
			i=R+1;
		}
	}
}
void dfs(int u){
	dfn[u]=++cnt,siz[u]=1;
	for(auto v:g[u])dfn1[v]=++cnt1,sz[u]++;
	for(auto v:g[u])
		dfs(v),siz[u]+=siz[v];
}
ll bit[300004];
int bit2[300004];
void upd(int i,ll x){
	for(;i<=tot;i+=i&-i)bit[i]+=x;
}
void upd2(int i,int x){
	for(;i<=tot;i+=i&-i)bit2[i]+=x;
}
ll ask(int i){
	ll ret=0;
	for(;i;i-=i&-i)ret+=bit[i];
	return ret;
}
int ask2(int i){
	int ret=0;
	for(;i;i-=i&-i)ret+=bit2[i];
	return ret;
}
ll qry(int l,int r){
	return ask(r)-ask(l-1);
}
int qry2(int l,int r){
	return ask2(r)-ask2(l-1);
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(int i=1;i<=q;i++)scanf("%d%d%d",&T[i],&L[i],&R[i]),nxt[L[i]]=max(nxt[L[i]],R[i]);
	s[0]='(';
	for(int i=1;i<=n;){
		if(nxt[i]==0)i++;
		else{
			int R=nxt[i];
			for(int j=i;j<=R;j++){
				s[++N]=s[j],pos[j]=N;
				R=max(R,nxt[j]);
			}
			i=R+1;
		}
	}
	s[N+1]=')';
	for(int i=1;i<=q;i++)L[i]=pos[L[i]],R[i]=pos[R[i]];
	stack<int>sta;
	for(int i=0;i<=N+1;i++){
		if(s[i]=='(')sta.push(i);
		if(s[i]==')'){
			int u=sta.top();sta.pop();
			rd[u]=i;
		}
	}
	built(1,0,N+1);
	dfn1[1]=cnt1=1,dfs(1);
	for(int i=1;i<=tot;i++)upd(dfn[i],(ll)sz[i]*(sz[i]+1)/2),upd2(dfn1[i],1);
	for(int i=1;i<=q;i++){
		int t=T[i],l=L[i],r=R[i];
		if(t==1){
			int p=fa[b[l]];
			upd(dfn[p],-sz[p]),sz[p]--;
			upd2(dfn1[b[l]],-1);
		}else{
			int ld=dfn[b[l]],rd=dfn[b[r]],len=qry2(dfn1[b[l]],dfn1[b[r]]);
			ll ans=qry(ld,rd+siz[b[r]]-1)+(ll)len*(len+1)/2;
			printf("%lld\n",ans);
		}
	}
}