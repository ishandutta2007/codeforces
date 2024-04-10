#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}

const int maxn=500010,inf=1e9;
int i,j,k,n,m,T,root,d1=1e9+5,d2=1e9+5;
ll ans=0,W[maxn*5];
int S[maxn*2],len;
struct node{
	int L,R,c;
}d[maxn];
bool cmp(node a,node b){
	return a.L>b.L;
}
namespace segment_tree{
	int cnt;
	ll Max[maxn*16],lazy[maxn*16];int son[maxn*16][2],D[maxn*16];
#define ls(x) son[x][0]
#define rs(x) son[x][1]
#define Mid ((L+R)>>1)
	void update(int root){
		if(Max[ls(root)]>Max[rs(root)])D[root]=D[ls(root)];
		else D[root]=D[rs(root)];
		Max[root]=max(Max[ls(root)],Max[rs(root)]);
	}
	void pushdown(int root,int L,int R){
		if(!ls(root))ls(root)=++cnt,Max[ls(root)]=-S[L],D[ls(root)]=S[L];
		if(!rs(root))rs(root)=++cnt,Max[rs(root)]=-S[Mid+1],D[rs(root)]=S[Mid+1];
		Max[ls(root)]+=lazy[root];
		lazy[ls(root)]+=lazy[root];
		Max[rs(root)]+=lazy[root];
		lazy[rs(root)]+=lazy[root];
		lazy[root]=0;
	}
	void add(int &root,int L,int R,int l,int r,int s){
		if(!root)root=++cnt,Max[root]=-S[L],D[root]=S[L];
		//cout<<" "<<"add"<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<s<<' '<<Max[root]<<' '<<D[root]<<endl;
		if(L==l&&R==r)lazy[root]+=s,Max[root]+=s;
		else{
			pushdown(root,L,R);
			if(r<=Mid)add(ls(root),L,Mid,l,r,s);
			else if(l>Mid)add(rs(root),Mid+1,R,l,r,s);
			else add(ls(root),L,Mid,l,Mid,s),add(rs(root),Mid+1,R,Mid+1,r,s);
			update(root);
		}
		//cout<<"end. "<<L<<' '<<R<<' '<<Max[root]<<' '<<D[root]<<endl;
	}
	pli find(int &root,int L,int R,int l,int r){
		//cout<<"find "<<root<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<Max[root]<<' '<<D[root]<<endl;
		if(!root)root=++cnt,Max[root]=-S[L],D[root]=S[L];
		if(L==l&&R==r)return make_pair(Max[root],D[root]);
		else{
			pushdown(root,L,R);
			if(r<=Mid)return find(ls(root),L,Mid,l,r);
			else if(l>Mid)return find(rs(root),Mid+1,R,l,r);
			else{
				pli w1=find(ls(root),L,Mid,l,Mid),w2=find(rs(root),Mid+1,R,Mid+1,r);
				if(w1.first>w2.first)return w1;
				else return w2;
			}
		}
	}
}using namespace segment_tree;

int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		int x=read(),y=read(),z=read();
		d[i]={min(x,y),max(x,y),z};
		S[++len]=min(x,y);
		S[++len]=max(x,y);
	}sort(d+1,d+1+n,cmp);
	sort(S+1,S+1+len);int x=unique(S+1,S+1+len)-S-1;
	for(i=1;i<=n;i++){
		d[i].L=lower_bound(S+1,S+1+x,d[i].L)-S;
		d[i].R=lower_bound(S+1,S+1+x,d[i].R)-S;
	}
	for(i=1;i<=n;i++){
		//cout<<' '<<d[i].L<<' '<<d[i].R<<' '<<d[i].c<<endl;
		add(root,1,x,d[i].R,x,d[i].c);
		if(i==n || d[i].L!=d[i+1].L){
			pli w=find(root,1,x,d[i].L,x);
		//	cout<<"w="<<w.first+d[i].L<<" "<<w.second<<endl;
			if(w.first+S[d[i].L]>ans){
				ans=w.first+S[d[i].L];
				d1=S[d[i].L];
				d2=w.second;
			}
		}//cerr<<"CNT="<<cnt<<endl;
	}cout<<ans<<endl;
	cout<<d1<<' '<<d1<<' '<<d2<<' '<<d2<<endl;
}