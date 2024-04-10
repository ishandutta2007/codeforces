#include<bits/stdc++.h>
#define ll long long
#define Mid (L+R>>1)
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=2000010;
struct edge{
	int l,r,w;
}e[maxn];
int i,j,k,n,m,T;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int tree[maxn*4],lazy[maxn*4];
void pushdown(int root){
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	tree[root*2]+=lazy[root];
	tree[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void update(int root){
	tree[root]=min(tree[root*2],tree[root*2+1]);
}
int query(int root,int L,int R,int l,int r){
	if(l==L && r==R){return tree[root];}
	else{
		pushdown(root);
		if(r<=Mid)return query(root*2,L,Mid,l,r);
		else if(l>Mid)return query(root*2+1,Mid+1,R,l,r);
		else return min(query(root*2,L,Mid,l,Mid),query(root*2+1,Mid+1,R,Mid+1,r));
	}
}
void add(int root,int L,int R,int l,int r,int s){
	if(l==L && r==R)tree[root]+=s,lazy[root]+=s;
	else{
		pushdown(root);
		if(r<=Mid)add(root*2,L,Mid,l,r,s);
		else if(l>Mid)add(root*2+1,Mid+1,R,l,r,s);
		else add(root*2,L,Mid,l,Mid,s),add(root*2+1,Mid+1,R,Mid+1,r,s);
		update(root);
	}
	//cout<<L<<' '<<R<<' '<<tree[root]<<endl;
}
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)e[i]={read(),read(),read()};
	sort(e+1,e+1+n,cmp);
	int p=1,ans=1e9;
	for(i=1;i<=n;i++){
		while(query(1,1,m-1,1,m-1)<1){
			if(p>n){cout<<ans<<endl;return 0;}
			add(1,1,m-1,e[p].l,e[p].r-1,1);
			++p;
		}
		ans=min(ans,e[p-1].w-e[i].w);
		add(1,1,m-1,e[i].l,e[i].r-1,-1);
	}cout<<ans<<endl;
}