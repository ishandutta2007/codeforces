#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=1e5+5;
int ch[N][26],fail[N],pos[N],loc[N],P;
vector<int> g[N];
int n,q,m;
char a[N];
inline void ins(int x){
	int p=0;
	for(int i=loc[x];i<loc[x+1];i++){
		int u=a[i]-'a';
		if(!ch[p][u]){
			ch[p][u]=++P;
			p=P;
		}
		else p=ch[p][u];
		pos[i]=p;
	}
}
inline void build(){
	queue<int> q;
	int i;
	for(i=0;i<26;i++) 
		if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty()){
		int p=q.front();q.pop();
		for(i=0;i<26;i++){
			if(!ch[p][i]) ch[p][i]=ch[fail[p]][i];
			else{
				q.push(ch[p][i]);
				fail[ch[p][i]]=ch[fail[p]][i];
			}
		}
	}
	for(i=1;i<=P;i++) g[fail[i]].push_back(i);
}
int lft[N],rgt[N],d[N],tot;
void dfs1(int u){
	lft[u]=++tot;
	for(auto v:g[u]){
		dfs1(v);
	}
	rgt[u]=tot;
}
int l[N],r[N],t[N];
ll ans[N];
vector<int> v1[N],v2[N];
int main(){
	int i,j,k;
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>(a+loc[i]);
		loc[i+1]=loc[i]+strlen(a+loc[i]);
		ins(i);
	}
	build();
	dfs1(0);
	for(i=1;i<=q;i++){
		cin>>l[i]>>r[i]>>t[i];
		v1[t[i]].push_back(i);
	}
	int B=sqrt(loc[n+1]);
	for(i=1;i<=n;i++){
		if(loc[i+1]-loc[i]>B){
			memset(d,0,sizeof(d));
			for(j=0;j<=n;j++) v2[j].clear();
			for(auto x:v1[i]){
				v2[r[x]].push_back(x);
				v2[l[x]-1].push_back(-x);
			}
			for(j=loc[i];j<loc[i+1];j++)
				for(k=lft[pos[j]];k<=tot;k+=lbt(k)) d[k]++;
			ll sum=0;
			for(j=1;j<=n;j++){
				for(k=rgt[pos[loc[j+1]-1]];k;k-=lbt(k)) sum+=d[k];
				for(k=lft[pos[loc[j+1]-1]]-1;k;k-=lbt(k)) sum-=d[k];
				for(auto x:v2[j]){
					if(x<0) ans[-x]-=sum;
					else ans[x]+=sum;
				}
			}
		}
	}
	memset(d,0,sizeof(d));
	for(i=0;i<=n;i++) v2[i].clear();
	for(i=1;i<=q;i++){
		if(loc[t[i]+1]-loc[t[i]]<=B){
			v2[r[i]].push_back(i);
			v2[l[i]-1].push_back(-i);
		}
	}
	for(i=1;i<=n;i++){
		for(k=rgt[pos[loc[i+1]-1]];k;k-=lbt(k)) d[k]++;
		for(k=lft[pos[loc[i+1]-1]]-1;k;k-=lbt(k)) d[k]--;
		for(auto x:v2[i]){
			if(x<0){
				for(j=loc[t[-x]];j<loc[t[-x]+1];j++)
					for(k=lft[pos[j]];k<=tot;k+=lbt(k)) ans[-x]-=d[k];				
			}
			else{
				for(j=loc[t[x]];j<loc[t[x]+1];j++)
					for(k=lft[pos[j]];k<=tot;k+=lbt(k)) ans[x]+=d[k];
			}
		}
	}
	for(i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}