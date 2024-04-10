#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;
string st;
string big;
int deb;
int arr[N];
int n;
int par[N];
char parc[N];
int nxt[N][26];
int go[N][26];
int link[N];
int elink[N];
int leaf[N];
int sz[N];
int pt=2;


void add_string(int i){
	int node=1;
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
vector<vector<int>>fin;
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>big;
	cin>>n;
	fin.resize(n+1);
	
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		arr[i]=k;
		cin>>st;
		add_string(i);
		sz[i]=st.size();
	}
	
	for(int i=1; i<=pt-1; i++){
		int x=get_link(i);
	}

	for(int i=1; i<=pt-1; i++){
		int x=exlink(i);
	}
	
	int node=1;
	int it=0;
	
	for(auto u:big){
		it++;
		deb=1;
		node=got(node, u);

		int node2=node;
		
		while(node2!=1){
			if(leaf[node2]){
				fin[leaf[node2]].pb(it);
			}
		
			node2=elink[node2];
			
		}
	
	}
	
	for(int i=1; i<=n; i++){
		if(fin[i].size()<arr[i]){
			cout<<-1<<endl;
			continue;
		}
		int mini=1e18;
		for(int j=arr[i]-1; j<fin[i].size(); j++){
			mini=min(mini, fin[i][j]-fin[i][j-arr[i]+1]+sz[i]);
		}
		cout<<mini<<endl;
	}
	
	return 0;
}