#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
struct PQ{
	priority_queue<ll>A,B;
	ll sum;int sz;
	PQ(){sum=sz=0;}
	void got(){while(!B.empty()&&A.top()==B.top())A.pop(),B.pop();}
	void push(ll x){A.push(x),sz++,sum+=x;}
	void erase(ll x){B.push(x),sz--,sum-=x;}
	void pop(){got(),sz--,sum-=A.top(),A.pop();}
	ll top(){got();return A.top();}
	int size(){return sz;}
	bool empty(){got();return A.empty();}
}h[250004];
vector<pii>tr[250004];
int deg[250004],n;
int ord[250004],tg[250004];
ll f[250004][2];
bool cmp1(pii A,pii B){return deg[A.fi]>deg[B.fi];}
bool cmp2(int A,int B){return deg[A]<deg[B];}
void del(int x){
	for(auto [y,w]:tr[x]){
		if(deg[y]<=deg[x])break;
		h[y].push(w);
	}
}
void dfs(int x,int fa,int T){
	f[x][0]=f[x][1]=1e12;
	tg[x]=T;
	int rem=deg[x]-T;
	ll res=0;
	while(h[x].size()>rem)h[x].pop();
	vector<ll>A,B;
	for(auto [y,w]:tr[x])if(y!=fa){
		if(deg[y]<=T)break;
		dfs(y,x,T);
		ll a=f[y][0]+w,b=f[y][1];
		if(a<=b)res+=a,rem--;
		else res+=b,A.push_back(a-b),h[x].push(a-b);
	}
	if(rem<=0){
		for(auto y:A)h[x].erase(y);
		f[x][0]=f[x][1]=res;
		return;
	}
	while(h[x].size()>rem)B.push_back(h[x].top()),h[x].pop();
	if(h[x].size()==rem)f[x][1]=res+h[x].sum;
	while(h[x].size()>rem-1)B.push_back(h[x].top()),h[x].pop();
	if(h[x].size()==rem-1)f[x][0]=res+h[x].sum;
	for(auto y:B)h[x].push(y);
	for(auto y:A)h[x].erase(y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		tr[u].push_back({v,w}),deg[u]++;
		tr[v].push_back({u,w}),deg[v]++;
	}
	for(int i=1;i<=n;i++)sort(tr[i].begin(),tr[i].end(),cmp1);
	for(int i=1;i<=n;i++)ord[i]=i,tg[i]=-1;sort(ord+1,ord+n+1,cmp2);
	for(int i=0,cur=1;i<n;i++){
		while(cur<=n&&deg[ord[cur]]<=i)del(ord[cur]),cur++;
		ll ans=0;
		for(int j=cur;j<=n;j++){
			int x=ord[j];
			if(tg[x]==i)continue;
			dfs(x,0,i),ans+=f[x][1];
		}
		printf("%lld ",ans);
	}
}