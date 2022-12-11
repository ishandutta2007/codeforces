#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int q,t[N*200][2],cnt,rt[N],mn[N*200];bool vis[N];
vector<int>v[N];
void insert(int id,int x){
	if(!rt[id])rt[id]=++cnt;
	int p=rt[id];
	for(int i=16;~i;i--){
		int d=x>>i&1;
		if(!t[p][d])t[p][d]=++cnt;
		mn[p]=min(mn[p],x);
		p=t[p][d];
	}
	mn[p]=x;
}
int query(int id,int x,int s){
	int p=rt[id];
	if(!p||mn[p]+x>s)return -1;
	for(int i=16;~i;i--){
		int d=x>>i&1;
		if(t[p][!d]&&mn[t[p][!d]]+x<=s)p=t[p][!d];
		else p=t[p][d];
	}
	return mn[p];
}
int main(){
	scanf("%d",&q);
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=100000;i++)for(int j=i;j<=100000;j+=i)v[j].push_back(i);
	for(int i=1,op,x,k,s;i<=q;i++){
		scanf("%d%d",&op,&x);
		if(op==2){
			scanf("%d%d",&k,&s);
			printf("%d\n",x%k?-1:query(k,x,s));
		}
		else if(!vis[x]){
			vis[x]=1;
			for(int j=0;j<v[x].size();j++)insert(v[x][j],x);
		}
	}
	return 0;
}