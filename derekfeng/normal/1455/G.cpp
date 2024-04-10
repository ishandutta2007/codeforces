#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,s,rd[200004];
char op[15];
int typ[200004],v[200004],w[200004];
vector<int>gr[200004];
void built(int id,int l,int r){
	if(r<l)return;
	for(int i=l;i<=r;i++){
		gr[id].push_back(i);
		if(typ[i]==0)continue;
		built(i,i+1,rd[i]-1),i=rd[i];
	}
}
ll h[200004];
map<int,ll>f[200004];
multiset<ll>g[200004];
void merge(map<int,ll>&f1,multiset<ll>&g1,ll &t1,map<int,ll>&f2,multiset<ll>&g2,ll &t2){
	if(f1.size()<f2.size())swap(f1,f2),swap(g1,g2),swap(t1,t2);
	for(auto x:f2){
		ll tmp=x.se+t2-t1;
		if(f1.count(x.fi)==0)f1[x.fi]=tmp,g1.insert(tmp);
		else{
			ll val=f1[x.fi];
			if(val>tmp){
				g1.erase(g1.find(val));
				f1[x.fi]=tmp,g1.insert(tmp);
			}
		}
	}
}
void calc(int id){
	ll &lev=h[id];
	f[id][v[id]]=0,g[id].insert(0);
	for(auto i:gr[id]){
		if(typ[i]==0){
			if(v[i]==s){lev+=w[i];continue;}
			ll val=g[id].empty()?1e18:*g[id].begin();
			if(f[id].count(v[i])){
				ll t=f[id][v[i]];
				f[id].erase(f[id].find(v[i]));
				g[id].erase(g[id].find(t));
			}
			val+=lev,lev+=w[i];
			f[id][v[i]]=val-lev,g[id].insert(val-lev);
		}else{
			ll t=f[id].count(v[i])?f[id][v[i]]+lev:1e18;
			if(f[id].count(v[i])){
				ll t=f[id][v[i]];
				f[id].erase(f[id].find(v[i]));
				g[id].erase(g[id].find(t));
			}
			if(t<1e18){
				calc(i),t+=h[i];
				merge(f[id],g[id],lev,f[i],g[i],t);
			}
		}
	}
	if(id==0){
		ll ans=1e18;
		for(auto x:f[id])ans=min(ans,x.se+lev);
		printf("%lld",ans);
	}
}
int main(){
	scanf("%d%d",&n,&s);
	stack<int>sta;
	for(int i=1;i<=n;i++){
		scanf("%s",op);
		if(*op=='s')typ[i]=0,scanf("%d%d",&v[i],&w[i]);
		if(*op=='i')typ[i]=1,scanf("%d",&v[i]),sta.push(i);
		if(*op=='e')typ[i]=2,rd[sta.top()]=i,sta.pop();
	}
	built(0,1,n),calc(0);
}