#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=100005;


int n;
set<int> a,b;
int c[maxn][2];
int v[maxn];
bool isr[maxn];

int rt;

int mini(int a,int b){
	if(a<b) return a;
	return b;
}


int maxi(int a,int b){
	if(a>b) return a;
	return b;
}
void dfs(int u,int l,int r){
	if(v[u]<=r&&v[u]>=l){
		if(a.count(v[u])) a.erase(v[u]);
	}
	if(c[u][0]!=-1){
		dfs(c[u][0],l,mini(r,v[u]-1));
	}
	if(c[u][1]!=-1){
		dfs(c[u][1],maxi(l,v[u]+1),r);
	}
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>c[i][0]>>c[i][1];
		if(!a.count(v[i])) a.insert(v[i]);
		if(c[i][0]!=-1)isr[c[i][0]]=1;
		if(c[i][1]!=-1)isr[c[i][1]]=1;
	}
	for(int i=1;i<=n;i++) if(!isr[i]) rt=i;
	int ans=0;
	dfs(rt,0,1000000000);
	for(int i=1;i<=n;i++){
		if(a.count(v[i]))ans++;
	}
	cout<<ans;
	return 0;
}//duliuXR