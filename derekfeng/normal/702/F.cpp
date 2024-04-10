#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=2e5+5;
mt19937_64 dzm(19260817);
int n,m;
ull key[N];
int tot,val[N],a[N],b[N],ans[N],s[2][N];
pii p[N];
int rt;
int node(int x){
	int i=++tot;
	key[i]=dzm(),val[i]=x;
	return i;
}
void push(int x,int A,int B){
	val[x]+=A,ans[x]+=B;
	a[x]+=A,b[x]+=B;
}
void pushdown(int i){
	if(a[i]||b[i]){
		if(s[0][i])push(s[0][i],a[i],b[i]);
		if(s[1][i])push(s[1][i],a[i],b[i]);
		a[i]=0,b[i]=0;
	}
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	pushdown(x),pushdown(y);
	if(key[x]<key[y]){
		s[1][x]=merge(s[1][x],y);
		return x;
	}
	s[0][y]=merge(x,s[0][y]);
	return y;
}
void split(int i,int k,int &x,int &y){
	if(!i){x=y=0;return;}
	pushdown(i);
	if(val[i]<k)x=i,split(s[1][i],k,s[1][i],y);
	else y=i,split(s[0][i],k,x,s[0][i]);
}
void dfs(int i,int c){
	pushdown(i);
	val[i]-=c,ans[i]++;
	a[i]=0,b[i]=0;
	if(s[0][i])dfs(s[0][i],c),s[0][i]=0;
	if(s[1][i])dfs(s[1][i],c),s[1][i]=0;
	int A,B;
	split(rt,val[i],A,B);
	rt=merge(merge(A,i),B);
}
void iter(int x){
	pushdown(x);
	if(s[0][x])iter(s[0][x]);
	if(s[1][x])iter(s[1][x]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&p[i].se,&p[i].fi),p[i].fi=-p[i].fi;
	sort(p+1,p+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x;scanf("%d",&x);
		int A,B;
		split(rt,x,A,B);
		rt=merge(merge(A,node(x)),B);
	}
	for(int i=1;i<=n;i++){
		int c=p[i].se;
		int A,B,C;
		split(rt,c,A,B);
		split(B,c+c,B,C);
		if(C)push(C,-c,1);
		rt=merge(A,C);
		if(B)dfs(B,c);
	}
	iter(rt);
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
}