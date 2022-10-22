#include<bits/stdc++.h>
using namespace std;
inline int query(vector<int> S){
	int res;
	if(S.size()<2ull) return 0;
	cout<<"? "<<S.size()<<endl;
	for(int i=S.size();i--;) cout<<S[i]<<" ";
	cout<<endl;cin>>res;
	return res;
}
inline int ask(int u,vector<int> S){
	int t=query(S);
	S.push_back(u);
	return query(S)-t;
}
int n,u,d[999],fa[999],d1[999],d2[999];bool vis[999];queue<int> q;vector<int> vec,sn[999],yny[2],edg;
void slv(int l,int r,int val){
	if(!val) return;
	if(l==r){sn[fa[vec[l]]=u].push_back(vec[l]);vis[vec[l]]=1;q.push(vec[l]);return;}
	int md=l+r>>1,t;vector<int> ls;
	for(int i=l;i<=md;++i) ls.push_back(vec[i]);
	t=ask(u,ls);
	slv(l,md,t);slv(md+1,r,val-t);
}
void Dfs(int nw,int fa,int*dis){
	for(int i=sn[nw].size();i--;) if(sn[nw][i]^fa) dis[sn[nw][i]]=dis[nw]+1,Dfs(sn[nw][i],nw,dis);
}
void dfs(int nw){for(int i=sn[nw].size();i--;) d[sn[nw][i]]=(d[nw]^1),dfs(sn[nw][i]);}
inline bool cmp(int A,int B){return d1[A]<d1[B];}
int main(){
	cin>>n;
	for(q.push(1),vis[1]=1;!q.empty();q.pop(),vec.clear()){
		for(int i=1;i<=n;++i) if(!vis[i]) vec.push_back(i);
		if(!vec.empty()) slv(0,vec.size()-1,ask(u=q.front(),vec));
	}
	dfs(1);
	for(int i=1;i<=n;++i) yny[d[i]&1].push_back(i);
	if(!query(yny[0])&&!query(yny[1])){
		cout<<"Y "<<yny[0].size()<<endl;
		for(int i=yny[0].size();i--;) cout<<yny[0][i]<<" ";
		cout<<endl;
		return 0;
	}
	if(query(yny[0])) edg=yny[0];
	else edg=yny[1];
	for(int l,r,md;edg.size()>2ull;){
		shuffle(edg.begin(),edg.end(),mt19937(time(0)));
		l=0;r=edg.size()-1;md=l+r>>1;vec.clear();
		for(int i=l;i<=md;++i) vec.push_back(edg[i]);
		if(query(vec)) edg=vec;
		if(edg.size()<20ull) for(int i=edg.size(),flg=1;i--&&flg;) for(int j=i;j--;){
			vec.clear();vec.push_back(edg[i]);vec.push_back(edg[j]);
			if(query(vec)){edg=vec;flg=0;break;}
		}
	}
	for(int i=2;i<=n;++i) sn[i].push_back(fa[i]);
	Dfs(edg[0],0,d1);Dfs(edg[1],0,d2);
	vec.clear();
	for(int i=1;i<=n;++i) if(d1[i]+d2[i]==d1[edg[1]]) vec.push_back(i);
	sort(vec.begin(),vec.end(),cmp);
	cout<<"N "<<vec.size()<<endl;
	for(int i=vec.size();i--;) cout<<vec[i]<<" ";
	cout<<endl;
	return 0;
}