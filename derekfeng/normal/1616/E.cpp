#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,it[26];
vector<int>v[26];
int sz[300000];
void built(int i,int l,int r){
	sz[i]=r-l+1;
	if(l!=r){
		int md=(l+r)>>1;
		built(i<<1,l,md),built(i<<1|1,md+1,r);
	}
}
int qry(int i,int l,int r,int p){
	if(l==r)return sz[i];
	int md=(l+r)>>1;
	if(p<=md)return qry(i<<1,l,md,p);
	return sz[i<<1]+qry(i<<1|1,md+1,r,p);
}
void upd(int i,int l,int r,int p){
	sz[i]--;
	if(l==r)return;
	int md=(l+r)>>1;
	if(p<=md)upd(i<<1,l,md,p);
	else upd(i<<1|1,md+1,r,p);
}
char s[100005],t[100005];
void sol(){
	scanf("%d%s%s",&n,s+1,t+1);
	for(int i=0;i<26;i++)v[i].clear(),it[i]=0;
	for(int i=1;i<=n;i++)v[s[i]-'a'].push_back(i);
	ll tmp=0,ans=1e18;
	built(1,1,n);
	for(int i=0;i<n;i++){
		if(i>0){
			int tt=t[i]-'a';
			if(it[tt]==v[tt].size())break;
			int u=v[tt][it[tt]++];
			tmp+=qry(1,1,n,u)-1,upd(1,1,n,u);
		}
		int tt=t[i+1]-'a',nxt=n+1;
		for(int j=0;j<tt;j++)
			if(it[j]<v[j].size())nxt=min(nxt,v[j][it[j]]);
		if(nxt==n+1)continue;
		ans=min(ans,tmp+qry(1,1,n,nxt)-1);
	}
	if(ans==1e18)puts("-1");
	else printf("%lld\n",ans);
	
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}