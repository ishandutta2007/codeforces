#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,ans=1,x,q,inv[200004];
int p[200004],a[200004],res[200004];
map<int,int>mp[200004];
map<int,int>t;
map<int,int>lev;
vector<int>G[200004];
void upd(int p,int x){
	for(auto y:G[x])mp[p][y]++;
}
void fupd(int p,int x){
	for(auto y:G[x]){
		mp[p][y]--;
		if(mp[p][y]<t[y]){
			t[y]=mp[p][y];
			ans=(long long)ans*inv[y]%MOD;
		}
	}
}
int main(){
	inv[1]=1;
	for(int i=2;i<=2e5;i++)
		inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=2;i<=2e5;i++){
		int now=i;
		for(int j=2;j*j<=i;j++)
			while(now%j==0)now/=j,G[i].push_back(j);
		if(now>1)G[i].push_back(now);
	}
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		upd(i,x);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&p[i],&a[i]);
		upd(p[i],a[i]);
	}
	for(int i=1;i<=n;i++){
		for(auto it=mp[i].begin();it!=mp[i].end();it++){
			int x=it->first,y=it->second;
			lev[x]++;
			if(t.find(x)==t.end())t[x]=y;
			else t[x]=min(t[x],y);
		}
	}
	ans=1;
	for(auto it=t.begin();it!=t.end();it++){
		if(lev[it->first]!=n)it->second=0;
		for(int k=0;k<it->second;k++)
			ans=(long long)ans*(it->first)%MOD;
	}
	for(int i=q;i;i--){
		res[i]=ans;
		fupd(p[i],a[i]);
	}
	for(int i=1;i<=q;i++)printf("%d\n",res[i]);
}