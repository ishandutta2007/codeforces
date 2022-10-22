#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int n,m;
int al,bl,ar,br,v[100004],f[100004][2];
set<pii>st0,st1;
void dfs(int x,int t){
	if(x==0)return;
	int lst=f[x][t];
	dfs(lst,t^1);
	for(int i=lst+1;i<=x;i++)printf("%d ",t);
}
int main(){
	scanf("%d%d",&n,&m);
	memset(f,-1,sizeof(f));
	st0.insert(mkp(0,0)),st1.insert(mkp(0,0));
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&v[i],&al,&bl,&ar,&br);
		bool tmpl=st0.empty(),tmpr=st1.empty();
		if(al<=v[i]&&v[i]<=bl){
			if(!tmpr)st0.insert(mkp(v[i-1],i-1));
			while(!st0.empty()&&(*st0.begin()).fi<ar)st0.erase(st0.begin());
			while(!st0.empty()&&(*st0.rbegin()).fi>br)st0.erase(--st0.end());
			if(!st0.empty())f[i][0]=(*st0.begin()).se;
		}else st0.clear();
		if(ar<=v[i]&&v[i]<=br){
			if(!tmpl)st1.insert(mkp(v[i-1],i-1));
			while(!st1.empty()&&(*st1.begin()).fi<al)st1.erase(st1.begin());
			while(!st1.empty()&&(*st1.rbegin()).fi>bl)st1.erase(--st1.end()); 
			if(!st1.empty())f[i][1]=(*st1.begin()).se;
		}else st1.clear();
	}
	if(!st0.empty()){
		puts("Yes");
		dfs(n,0);
		return 0;
	}
	if(!st1.empty()){
		puts("Yes");
		dfs(n,1);
		return 0;
	}
	puts("No");
}