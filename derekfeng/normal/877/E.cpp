#include <bits/stdc++.h>
using namespace std;
void read(string &s){
	s="";char ch=getchar();
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
int n,q,cnt=0,n_=1;
int dat[530000],num[530000],sz[530000];
vector<int>g[200004]; 
int l[200004],r[200004];
void dfs(int x){
	l[x]=cnt++;
	for (int i=0;i<g[x].size();i++) dfs(g[x][i]); 
	r[x]=cnt-1;
}
void init(int id,int l,int r){
	sz[id]=1;
	if (l==r)
		return;
	init(id*2+1,l,(l+r)/2);
	init(id*2+2,(l+r)/2+1,r);
	sz[id]=sz[id*2+1]*2;
	num[id]=num[id*2+1]+num[id*2+2];
}
void update(int l,int r,int id,int a,int b){
	if (a>r || l>b) return;
	if (a<=l && r<=b){
		int now=sz[id]-2*num[id];
		dat[id]^=1;
		num[id]+=now;
		int idd=id;
		if (id!=0) while (1){
			idd=(idd-1)/2;
			if (dat[idd]) now*=-1;
			num[idd]+=now;
			if (idd==0) break;
		}
		return;
	}
	update(l,(l+r)/2,id*2+1,a,b);
	update((l+r)/2+1,r,id*2+2,a,b);
}
int ans(int l,int r,int id,int a,int b){
	if (a>r || l>b) return 0;
	if (a<=l && r<=b){
		int ans1=num[id],ans2=sz[id]-num[id];
		int idd=id;
		if (id!=0) while (1){
			idd=(idd-1)/2;
			if (dat[idd]) swap(ans1,ans2); 
			if (idd==0) break;
		}
		return ans1;
	}
	return ans(l,(l+r)/2,id*2+1,a,b)+ans((l+r)/2+1,r,id*2+2,a,b);
}
int main(){
	cin>>n;
	while (n_<n) n_<<=1;
	for (int i=2;i<=n;i++){
		int x;scanf("%d",&x);
		g[x].push_back(i); 
	}
	dfs(1);
	for (int i=1;i<=n;i++) scanf("%d",&num[l[i]+n_-1]);
	init(0,0,n_-1);
	cin>>q;
	while (q--){
		string oper;int v;read(oper);scanf("%d",&v);
		if (oper[0]=='p'){
			update(0,n_-1,0,l[v],r[v]);
		}else{
			printf("%d\n",ans(0,n_-1,0,l[v],r[v]));
		}
	}
}