#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'

string big;
string st;
int x;

vector<string>vec;
vector<string>fin;


const int N=30000;
vector<vector<int>>dp;

int par[N];
char parc[N];
int nxt[N][10];
int go[N][10];
int link[N];
int elink[N];
int leaf[N];
int sz[N];
int pt=2;





void add_string(int i){
	int node=1;
	for(auto ch:st){
		int c=ch-'0';
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
	int c=ch-'0';
 
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









void f(string st, int val){
	if(val==0){
		vec.pb(st);
		return;
	}
	for(int i=2; i<=9; i++){
		if(val>=i){
			st+=char(i+'0');
			f(st, val-i);
			st.pop_back();
		}
	}
}


 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>big;
	cin>>x;
	if(x==1){
		int ans=0;
		for(auto ch:big){
			if(ch=='1'){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	string re="";
	f(re, x);
	
	for(auto u:vec){
		bool che=1;
		for(int i=0; i<u.size(); i++){
			int sum=0;
			if(che==0){
				break;
			}
			for(int j=i; j<u.size(); j++){
				sum+=(u[j]-'0');
				if(sum!=x && x%sum==0){
					che=0;
					break;
				}
			}
		}
		if(che){
			fin.pb(u);
		}
	}
	
	int val=0;
	for(auto u:fin){
		val++;
		st=u;
		add_string(val);
	}
	
	dp.resize(big.size()+1);
	
	for(int i=0; i<big.size()+1; i++){
		dp[i].resize(pt+5);
	}
	
	int nn=big.size()+1;
	int mm=pt+5;
	
	for(int i=0; i<nn; i++){
		for(int j=0; j<mm; j++){
			dp[i][j]=-1e9;
		}
	}
	
	dp[0][1]=0;
	
	for(int i=0; i<big.size(); i++){
		for(int node=1; node<=pt-1; node++){
			int node2=got(node, big[i]);
			if(!leaf[node2]){
				dp[i+1][node2]=max(dp[i+1][node2], dp[i][node]+1);
			}
			dp[i+1][node]=max(dp[i+1][node], dp[i][node]);
		}
	}
	int maxi=0;
	
	for(int i=1; i<=pt-1; i++){
		maxi=max(maxi, dp[big.size()][i]);
	}
	
	cout<<big.size()-maxi;
	
	
	return 0;
}