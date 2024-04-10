#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
int n,m,u[200005],v[200005],first[200005],nxt[200005];
int q,x;
int c[100005];
vector<int> in[100005];
int in_cnt[100005],out_cnt[100005];
ll ans;
void upd(int pos,int opt){// 0: in -> out ; 1: out -> in 
	ans-=1ll*in_cnt[pos]*out_cnt[pos];
	if (opt==0){
		in_cnt[pos]--;
		out_cnt[pos]++;
	}
	if (opt==1){
		out_cnt[pos]--;
		in_cnt[pos]++;
	}
	ans+=1ll*in_cnt[pos]*out_cnt[pos];
	return;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)c[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		if (u[i]<v[i]){
			in[u[i]].push_back(v[i]);
			in_cnt[u[i]]++;
			out_cnt[v[i]]++;
		}
		else{
			in[v[i]].push_back(u[i]);
			in_cnt[v[i]]++;
			out_cnt[u[i]]++;
		}
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+m]=v[i],v[i+m]=u[i];
		nxt[i+m]=first[u[i+m]],first[u[i+m]]=i+m;
	}
	for (int i=1;i<=n;i++)ans+=1ll*in_cnt[i]*out_cnt[i];
	cout<<ans<<endl;
	cin>>q;
	for (int T=1;T<=q;T++){
		int x;
		scanf("%d",&x);
		for (int i=0;i<in[x].size();i++){
			int qwq=in[x][i];
			if (c[qwq]<c[x])continue;
			upd(x,0);
			in[qwq].push_back(x);
			upd(qwq,1);
		}
		c[x]=n+T;
		in[x].clear();
		printf("%lld\n",ans);
	}
	return 0;
}