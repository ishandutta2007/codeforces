#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,b[maxn],chs[maxn];
namespace segment_tree{
#define Mid ((L+R)>>1)
#define ls(x) ((x)*2)
#define rs(x) ((x)*2+1)
	int Min[maxn*4],Id[maxn*4],lazy[maxn*4];
	void update(int root){
		Min[root]=min(Min[ls(root)],Min[rs(root)]);
		if(Min[ls(root)]>Min[rs(root)])Id[root]=Id[rs(root)];
		else Id[root]=Id[ls(root)];
	}
	void pushdown(int root){
		if(lazy[root]){
			lazy[ls(root)]+=lazy[root];
			Min[ls(root)]+=lazy[root];
			lazy[rs(root)]+=lazy[root];
			Min[rs(root)]+=lazy[root];
			lazy[root]=0;
			update(root);
		}
	}
	void build(int root,int L,int R){
		if(L==R)Min[root]=lazy[root]=0,Id[root]=L;
		else{
			lazy[root]=0;
			build(ls(root),L,Mid);
			build(rs(root),Mid+1,R);
			update(root);
		}
	}
	void change(int root,int L,int R,int l,int r,int s){
	//	cout<<"CHANGE "<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<Min[root]<<' '<<lazy[root]<<endl;
		if(L==l && R==r){
			Min[root]+=s;
			lazy[root]+=s;
		}else{
			pushdown(root);
			if(r<=Mid)change(ls(root),L,Mid,l,r,s);
			else if(l>Mid)change(rs(root),Mid+1,R,l,r,s);
			else change(ls(root),L,Mid,l,Mid,s),change(rs(root),Mid+1,R,Mid+1,r,s);
			update(root);
		}
	}
	int tree[maxn];
	int lowbit(int x){return x&(-x);}
	void add(int x,int s){for(;x<=n;x+=lowbit(x))tree[x]+=s;}
	int find(int x){int ans=0;for(;x;x-=lowbit(x))ans+=tree[x];return ans;}
}
using namespace segment_tree;
struct A{
	int id,w;
}a[maxn];
bool cmp(A x,A y){
	return x.w<y.w;
}
vector<int>V[maxn];
int main(){
	cin>>T;
	while(T--){
		n=read();m=read();
		for(i=1;i<=n;i++)tree[i]=0;
		build(1,1,n+1);
		for(i=1;i<=n+1;i++)V[i].clear();
		for(i=1;i<=n;i++)a[i].w=read(),a[i].id=i,change(1,1,n+1,i+1,n+1,1),V[i+1].push_back(a[i].w);
		for(i=1;i<=m;i++)b[i]=read();
		sort(b+1,b+1+m);
		sort(a+1,a+1+n,cmp);
		int p1=0,p2=0,last=1;
		ll ans=0;
		for(i=1;i<=n;i++){
			if(a[last].w!=a[i].w)
				while(last<i)add(1,1),add(a[last].id+1,-1)/*,cout<<i<<last<<' '<<a[last].id<<endl*/,++last;
//			cout<<"find "<<a[i].id<<endl;
			ans+=find(a[i].id);
		}
//		cout<<"ANS:"<<ans<<endl;
		for(i=1;i<=m;i++){
			while(p1!=n && a[p1+1].w<=b[i]){
				p1++;
				change(1,1,n+1,a[p1].id+1,n+1,-1);
			}
			while(p2!=n && a[p2+1].w<b[i]){
				p2++;
				change(1,1,n+1,1,a[p2].id,1);
			}
			ans+=Min[1];chs[i]=Id[1];//V[chs[i]].push_back(b[i]);
		//	cout<<"i choose "<<Id[1]<<" ADD"<<Min[1]<<endl;
			if(chs[i]!=1)change(1,1,n+1,1,chs[i]-1,1);
		}
		/*
		for(i=1;i<=n+1;i++)
			for(j=0;j<V[i].size();j++)printf("%d ",V[i][j]);
		*/printf("%lld\n",ans);
		//puts("");
	}
}