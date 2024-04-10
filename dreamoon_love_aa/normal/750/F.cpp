#include <bits/stdc++.h>
using namespace std;

const int N = 200;

int ret,d[N],h,num,haha;

bool is[N],vis[N];

vector<int> adj[N];

void query(int x){
	printf("? %d\n",x);fflush(stdout);
}

void print(int x){
	printf("! %d\n",x);fflush(stdout);
	if(haha)printf("! %d\n",x);fflush(stdout);
}
int input(int x){
	int k,i,u;
	cin>>k;--num;is[x]=1;
	for(i=0;i<k;++i)
		cin>>u,adj[x].push_back(u),adj[u].push_back(x);

	return k;
}
void sol(int x){
	int k,u,i;
	vis[x]=1;
	if(!is[x] && num>0){
		query(x);
		k= input(x);
		if(k==1){d[x]=1;return;}
		if(k==2)ret= x;
	}
	if(d[x]>=h)return;
	for(i=0;i<adj[x].size();++i){
		u= adj[x][i];
		if(!vis[u]){
			d[u]= d[x]+1;
			sol(u);
			if(d[u]!=d[x]+1 &&d[u]+1!=d[x]){
				d[x]= d[u]+1;
				return;
			}
		}
	}
}

void quest(){
	int u,k,i,x,v,st;ret=-1;
	cin>>h;
	memset(is,0,sizeof(is));
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	for(i=0;i<N;++i)adj[i].clear();
	num=16;
	query(1);
	k= input(1);
	u= 1;
	if(k==2){print(1);return;}
	if(k!=1){
		u= adj[1][0];

		while(1){
			query(u);
			
			k= input(u);
			
			if(k==2){print(u);return;}

			if(k==1)break;
			
			for(i=0;i<adj[u].size();++i)if(!is[adj[u][i]]){u= adj[u][i];break;}
		}
	}
	
	vis[u]=1,st= adj[u][0],vis[st]=1;
	d[st]=2;
	
	ret=-1;
	
	sol(st);
	
	if(ret==-1)
		for(i=1;i<N;++i)if(!is[i] && d[i]==h)ret= i;
	
	print(ret);
}

int main(){
	int t;cin>>t;while(t--){
           if(!t)haha=1;
           quest();
        }
}