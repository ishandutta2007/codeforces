#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<int>tr[100004];
int n,t;
int tot,cnt,dfn[100004],low[100004],cmp[100004];
stack<int>st;
bool ins[100004],vis[100004];
void tarjan(int x){
	dfn[x]=low[x]=++tot;
	st.push(x),ins[x]=1;
	for(auto y:tr[x]){
		if(!dfn[y])tarjan(y);
		if(ins[y])low[x]=min(low[x],low[y]);
	}
	if(dfn[x]==low[x]){
		++cnt;
		for(;;){
			int u=st.top();st.pop();
			cmp[u]=cnt,ins[u]=0;
			if(u==x)break;
		}
	}
}
void check(int x){
	vis[x]=1,tot++;
	for(auto y:tr[x])if(!vis[y])check(y);
}
pii a[100004];
void sol(){
	scanf("%d",&n),tot=cnt=0;
	for(int i=1;i<=n;i++)tr[i].clear(),dfn[i]=low[i]=cmp[i]=ins[i]=vis[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i].fi),a[i].se=i;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)tr[a[i+1].se].push_back(a[i].se);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].fi),a[i].se=i;
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)tr[a[i+1].se].push_back(a[i].se);
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
	tot=0;
	for(int i=1;i<=n;i++)if(cmp[i]==cnt){check(i);break;}
	for(int i=1;i<=n;i++)putchar((cmp[i]==cnt&&tot==n)?'1':'0');
	puts("");
}
int main(){
	scanf("%d",&t);
	while(t--)sol();
}