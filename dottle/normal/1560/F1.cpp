#include<bits/stdc++.h>
using namespace std;

int u[101],cnt,t,K,fl,sm,over;
string n,s;

void dfs(int k);

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>K;
		over=0,fl=0,sm=0,s.clear(),cnt=0,memset(u,0,sizeof(u));
		dfs(0);
		end: n;
	}
}

void dfs(int k){
	if(k==n.size()){
		cout<<s<<endl;
		over=1;
	}
	int nw=n[k],pr=fl;
	if(over==1)return;
	if(fl){
		if(sm<K)s+='0',dfs(k+1);
		if(over==1)return;
		for(int i='0';i<=nw;i++)
			if(u[i]){
				s+=(char)i,dfs(k+1);
				break;
			}
		if(over==1)return;
	}
	if(u[nw])s+=nw,dfs(k+1),s.pop_back();
	else if(sm<K)u[nw]=1,sm++,s+=nw,dfs(k+1),s.pop_back(),sm--,u[nw]=0;
	if(over==1)return;
	if(nw!=9){
		if(u[nw+1])s+=nw+1,fl=1,dfs(k+1),fl=pr,s.pop_back();
		else if(sm<K)u[nw+1]=1,sm++,s+=nw+1,fl=1,dfs(k+1),s.pop_back(),fl=pr,sm--,u[nw+1]=0;
		if(over==1)return;
		for(int i=nw+1;i<='9';i++){
			if(u[i]){
			
				s+=i,fl=1,dfs(k+1),fl=pr,s.pop_back();
			break;}
		}
	}
	if(over==1)return;
}