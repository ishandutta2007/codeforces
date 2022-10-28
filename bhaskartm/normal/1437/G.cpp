#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'




const int N=3e5+5;
string st;
int arr[N];
int n, m;
int par[N];
char parc[N];
int nxt[N][26];
int go[N][26];
int link[N];
int elink[N];
int leaf[N];
int sz[N];
int pt=2;
int node;

multiset<int>se[N];

map<string, int>ma;

int pos[N];
 
void add_string(int i){
	node=1;
	for(auto ch:st){
		int c=ch-'a';
		if(nxt[node][c]==0){
			nxt[node][c]=pt;
			pt++;
		}
		par[nxt[node][c]]=node;
		parc[nxt[node][c]]=ch;
		node=nxt[node][c];
	}
	leaf[node]=i;
}
 
 
int got(int v, char ch);
 
int get_link(int v){
	if(link[v]==0){
		if(v==1 || par[v]==1){
			link[v]=1;
		}
		else{
			link[v]=got(get_link(par[v]), parc[v]);
		}
	}
	return link[v];
}
 
 
int got(int v, char ch){
	int c=ch-'a';
 
	if(go[v][c]==0){
		if(nxt[v][c]!=0){
			go[v][c]=nxt[v][c];
			
		}
		else{
			go[v][c] = v==1 ? 1 : got(get_link(v), ch); 
		}
	}
	return go[v][c];
}
 
 
int exlink(int v){
	if(v==1 || par[v]==1){
		elink[v]=1;
		return elink[v];
	}
	if(elink[v]==0){
		if(leaf[link[v]]){
			elink[v]=link[v];
		}
		else{
			elink[v]=exlink(link[v]);
		}
	}
	return elink[v];
}



 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>st;
		int vals=ma[st];
		if(vals==0){
			add_string(i);
			ma[st]=node;
			se[node].insert(0);
			pos[i]=node;
			arr[i]=0;
		}
		else{
			pos[i]=vals;
			se[vals].insert(0);
			arr[i]=0;
		}
	}

	for(int i=1; i<=pt-1; i++){
		int x=get_link(i);
	}
	for(int i=1; i<=pt-1; i++){
		int x=exlink(i);
	}
	
	while(m--){
		int ty;
		cin>>ty;
		if(ty==1){
			int i, x;
			cin>>i>>x;
			int node=pos[i];
			se[node].erase(se[node].find(arr[i]));
			arr[i]=x;
			se[node].insert(arr[i]);
		}
		else{
			string t;
			cin>>t;
			int node=1;
			int ans=-1;
			for(auto ch:t){
				node=got(node, ch);
				int node2=node;
				while(node2!=1){
					if(leaf[node2]){
						auto it=se[node2].end();
						it--;
						ans=max(ans, (*it));
					}
					node2=elink[node2];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}