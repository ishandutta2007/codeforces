#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int B=320;
int n,q,cur,tot=1;
string s[100005];
vector<int>vec[100005];
int K[100005],L[100005],R[100005];
ll ans[100005];
int nxt[100005][26],kmp[100005];
vector<int>tr[100005];
void ins(int i){
	int cur=1;
	for(auto c:s[i]){
		if(!nxt[cur][c-'a'])nxt[cur][c-'a']=++tot;
		cur=nxt[cur][c-'a'],vec[i].push_back(cur);
	}
}
void getac(){
	fill(nxt[0],nxt[0]+26,1);
	queue<int>q;q.push(1);kmp[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			int v=nxt[u][i],Kmp=kmp[u];
			if(!v){nxt[u][i]=nxt[Kmp][i];continue;}
			kmp[v]=nxt[Kmp][i],q.push(v);
		}
	}
}
vector<pii>ask[100005];
vector<int>qry[100005];
int f[100005];
void init(int i){
	for(auto j:tr[i])init(j),f[i]+=f[j];
}
int dfn[100005],siz[100005],cnt;
void getsiz(int i){
	siz[i]=1,dfn[i]=++cnt;
	for(auto j:tr[i])getsiz(j),siz[i]+=siz[j];
}
int b1[320],b2[100005];
struct BLOCK{
	void upd(int l,int r){
		int pl=(l+B-1)/B,pr=(r+B-1)/B;
		if(pl==pr){
			for(int i=l;i<=r;i++)b2[i]++;
			return;
		}
		for(int i=l;i<=pl*B;i++)b2[i]++;
		for(int i=pl+1;i<pr;i++)b1[i]++;
		for(int i=r;i>(pr-1)*B;i--)b2[i]++;
	}
	int qry(int i){
		return  b2[i]+b1[(i+B-1)/B];
	}
}ds;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s[i],ins(i);
	getac();
	for(int i=1;i<=tot;i++)tr[kmp[i]].push_back(i);
	for(int i=1;i<=q;i++){
		cin>>L[i]>>R[i]>>K[i];
		if(s[K[i]].size()>B)ask[K[i]].push_back({L[i]-1,-i}),ask[K[i]].push_back({R[i],i});
		else qry[L[i]-1].push_back(-i),qry[R[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)if(s[i].size()>B&&!ask[i].empty()){
		sort(ask[i].begin(),ask[i].end());
		memset(f,0,sizeof(f));
		for(auto x:vec[i])f[x]++;
		init(0);ll sum=0;int it=0;
		while(it<ask[i].size()&&ask[i][it].fi==0)it++;
		for(int j=1;j<=n;j++){
			sum+=f[vec[j].back()];
			while(it<ask[i].size()&&ask[i][it].fi==j){
				int id=ask[i][it].se;
				if(id<0)ans[-id]-=sum;
				else ans[id]+=sum;
				it++;
			}
		}
	}
	getsiz(0);
	for(int i=1;i<=n;i++){
		int t=vec[i].back();
		ds.upd(dfn[t],dfn[t]+siz[t]-1);
		for(auto j:qry[i]){
			int J=abs(j),x=j<0?-1:1;
			for(auto z:vec[K[J]])
				ans[J]+=x*ds.qry(dfn[z]);
		}
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
}