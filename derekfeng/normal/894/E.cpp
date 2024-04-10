#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
ll go(ll x){
	ll l=-1,r=1e5+1;
	while (r>l+1){
		ll mid=(l+r)/2;
		if (mid*(mid+1)/2<=x) l=mid;
		else r=mid;
	}
	return l;
}
vector<int>g[1000004];
vector<int>num[1000004];
bool inst[1000004];
struct STACK{
	int t,d[1000004];
	void init(){
		t=0;
	}
	void push_(int x){
		d[t++]=x,inst[x]=1;
	}
	void pop_(){
		t--,inst[d[t]]=0;
	}
	int top_(){
		return d[t-1];
	}
}st;
int cmp[1000004],cnt,tms,vis[1000004],low[1000004];
void tarjan(int x){
	vis[x]=low[x]=++tms;
	st.push_(x);
	for (int i=0;i<g[x].size();i++){
		if (!vis[g[x][i]]) tarjan(g[x][i]);
		if (inst[g[x][i]])low[x]=min(low[g[x][i]],low[x]);
	} 
	if (low[x]==vis[x]){
		++cnt;
		while (st.top_()!=x){
			cmp[st.top_()]=cnt;
			st.pop_();
		}
		cmp[x]=cnt,st.pop_();
	}
}
int n,m,s;
ll a[1000004];
vector<int>G[1000004];
vector<ll>N[1000004];
ll ho[100004],dp[1000004];
int main(){
	for (int i=1;i<100004;i++) ho[i]=ho[i-1]+1ll*i*(i+1)/2;
	read(n),read(m);
	for (int i=0;i<m;i++){
		int u,v,w;read(u),read(v),read(w);
		g[u].push_back(v),num[u].push_back(w);  
	}
	read(s);
	for (int i=1;i<=n;i++) if (!vis[i]) tarjan(i); 
	for (int i=1;i<=n;i++)
		for (int j=0;j<g[i].size();j++){
			if (cmp[i]!=cmp[g[i][j]]) G[cmp[i]].push_back(cmp[g[i][j]]),N[cmp[i]].push_back(num[i][j]); 
			else{
				ll val=go(num[i][j]);
				a[cmp[i]]+=(val+1)*num[i][j]-ho[val];
			}
		}
	for (int i=1;i<=cnt;i++){
		for (int j=0;j<G[i].size();j++) dp[i]=max(dp[i],dp[G[i][j]]+N[i][j]);
		dp[i]+=a[i];
	}
	write(dp[cmp[s]]);
}