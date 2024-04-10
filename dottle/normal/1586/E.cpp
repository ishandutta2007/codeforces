#include<bits/stdc++.h>
const int N=600050; 
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,id;
}e[N];int hd[N],S=1;
void add(int fr,int to){
    ++S,e[S]=(edge){to,hd[fr],S},hd[fr]=S;
}
int fa[N];
int gf(int k){return k==fa[k]?fa[k]:fa[k]=gf(fa[k]);}
int n,m,p[N],in[N];
stack<int> ans[N];
queue<int> q;

bool dfs(int k,int fa,int t,int id){
	int fl=0;
	if(k==t){
		ans[id].push(k);
		return 1; 
	}
	fore(k)if(_to!=fa)
		if(dfs(_to,k,t,id))
			fl=1,p[e[i].id>>1]^=1;
	if(fl)ans[id].push(k); 
	return fl;
}

void dfs(int k,int fa){
	fore(k)if(_to!=fa&&p[e[i].id>>1]){
		p[e[i].id>>1]=0;
		in[_to]--,in[k]--;
		if(in[_to]==1)q.push(_to);
		if(in[k]==1)q.push(k);
		dfs(_to,k);
		return ;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y; 
		int fx=gf(x),fy=gf(y);
		if(fx==fy)continue;
		fa[fx]=fy,add(x,y),add(y,x);
	}
	int Q;
	cin>>Q; 
	for(int i=1;i<=Q;i++){
		int x,y;
		cin>>x>>y;
		dfs(x,0,y,i);
	}
	int isa=0;
	for(int i=1;i<n;i++)
		if(p[i])
			isa=1,in[e[i*2].to]++,in[e[i*2+1].to]++;
	if(!isa){
		cout<<"YES"<<endl;
		for(int i=1;i<=Q;i++){
			cout<<ans[i].size()<<endl;
			while(!ans[i].empty()) 
				cout<<ans[i].top()<<' ',ans[i].pop();
			cout<<endl;	
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==1)
			q.push(i);
	int ans=0;
	while(q.size()){
		int nw=q.front();q.pop();
		if(in[nw]!=1)continue;
		ans++;
		dfs(nw,0);
		cout<<endl;
	}
	cout<<"NO"<<endl;
	cout<<ans;
}