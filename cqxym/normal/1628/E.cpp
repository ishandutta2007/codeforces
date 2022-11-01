#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
#define R register int
#define I inline
#define N 300001
I int Max(const int x,const int y){
	return x>y?x:y;
}
I void Swap(int&x,int&y){
	int t=x;
	x=y;
	y=t;
}
namespace Tree{
	struct Edge{
		int End,Len;
	};
	I Edge Pair(int y,int l){
		Edge res;
		res.End=y;
		res.Len=l;
		return res;
	}
	vector<Edge>G[N];
	int dep[N],h[N],sz[N],Top[N],f[N][19],g[N][19];
	I void PreDFS(int x,int F){
		for(R i=1;i!=19&&f[x][i-1]!=0;i++){
			f[x][i]=f[f[x][i-1]][i-1];
			g[x][i]=Max(g[x][i-1],g[f[x][i-1]][i-1]);
		}
		dep[x]=dep[F]+1;
		sz[x]=1;
		for(Edge T:G[x]){
			int v=T.End;
			if(v!=F){
				f[v][0]=x;
				g[v][0]=T.Len;
				PreDFS(v,x);
				sz[x]+=sz[v];
				if(sz[v]>sz[h[x]]){
					h[x]=v;
				}
			}
		}
	}
	I void ReDFS(int x,int t){
		Top[x]=t;
		if(h[x]!=0){
			ReDFS(h[x],t);
			for(Edge T:G[x]){
				int v=T.End;
				if(v!=h[x]&&v!=f[x][0]){
					ReDFS(v,v);
				}
			}
		}
	}
	I void Init(const int n){
		int x,y,w;
		for(R i=1;i!=n;i++){
			scanf("%d%d%d",&x,&y,&w);
			G[x].push_back(Pair(y,w));
			G[y].push_back(Pair(x,w));
		}
		PreDFS(1,0);
		ReDFS(1,1);
	}
	struct Path{
		int Lca,maxL;
		I void Clear(){
			Lca=maxL=0;
		}
	};
	I Path GetPath(int x,int y){
		if(dep[x]<dep[y]){
			Swap(x,y);
		}
		int l=dep[x]-dep[y];
		Path res;
		res.maxL=0;
		for(R i=0;i!=19&&l!=0;i++){
			if((l>>i&1)==1){
				res.maxL=Max(res.maxL,g[x][i]);
				x=f[x][i];
				l^=1<<i;
			}
		}
		if(x==y){
			res.Lca=x;
			return res;
		}
		for(R i=18;i!=-1;i--){
			if(f[x][i]!=f[y][i]){
				res.maxL=Max(res.maxL,Max(g[x][i],g[y][i]));
				x=f[x][i];
				y=f[y][i];
			}
		}
		res.Lca=f[y][0];
		res.maxL=Max(res.maxL,Max(g[x][0],g[y][0]));
		return res;
	}
	I Path operator+(Path A,Path B){
		if(A.Lca==0){
			return B;
		}
		if(B.Lca==0){
			return A;
		}
		Path C=GetPath(A.Lca,B.Lca);
		C.maxL=Max(C.maxL,Max(A.maxL,B.maxL));
		return C;
	}
}
namespace SegmentTree{
	int Tn;
	struct SegmentNode{
		Tree::Path Cur,ALL;
		int Tag;
	}T[1200000];
	I void InitTree(int p,int lf,int rt){
		if(lf==rt){
			T[p].ALL.Lca=lf;
			T[p].ALL.maxL=0;
		}else{
			InitTree(p<<1,lf,lf+rt>>1);
			InitTree(p<<1|1,lf+rt+2>>1,rt);
			T[p].ALL=T[p<<1].ALL+T[p<<1|1].ALL;
		}
	}
	I void Init(const int n){
		Tn=n;
		InitTree(1,1,n);
	}
	I void PutDown(int p,bool t){
		if(T[p].Tag!=0){
			if(T[p].Tag==1){
				T[p].Cur=T[p].ALL;
			}else{
				T[p].Cur.Clear();
			}
			if(t==true){
				T[p<<1].Tag=T[p].Tag;
				T[p<<1|1].Tag=T[p].Tag;
			}
			T[p].Tag=0;
		}
	}
	I void Modify(int p,int lf,int rt,const int l,const int r,const int type){
		if(l<=lf&&rt<=r){
			T[p].Tag=type;
		}else{
			PutDown(p,true);
			int mid=lf+rt>>1;
			if(l<=mid){
				Modify(p<<1,lf,mid,l,r,type);
			}
			if(r>mid){
				Modify(p<<1|1,mid+1,rt,l,r,type);
			}
			PutDown(p<<1,lf!=mid);
			PutDown(p<<1|1,mid+1!=rt);
			T[p].Cur=T[p<<1].Cur+T[p<<1|1].Cur;
		}
	}
	set<pair<int,int>>S;
	I void Cover(int opt,int l,int r){
		Modify(1,1,Tn,l,r,opt);
		auto seg=make_pair(l,r);
		auto T=S.lower_bound(seg);
		if(T!=S.begin()){
			T--;
			if(T->second>=l){
				int lf=T->first,rt=T->second;
				S.erase(T);
				S.insert(make_pair(lf,l-1));
				if(rt>r){
					S.insert(make_pair(r+1,rt));
				}
			}
		}
		vector<pair<int,int>>V;
		for(T=S.lower_bound(seg);T!=S.end()&&T->second<=r;T++){
			V.push_back(*T);
		}
		if(T!=S.end()&&T->first<=r){
			int rt=T->second;
			S.erase(T);
			S.insert(make_pair(r+1,rt));
		}
		for(auto T:V){
			S.erase(T);
		}
		if(opt==1){
			S.insert(seg);
		}
	}
	I int GetAns(int x){
		bool tag=false;
		if(S.empty()==false){
			auto T=S.upper_bound(make_pair(x,N));
			if(T!=S.begin()){
				T--;
				if(T->second>=x){
					tag=true;
				}
			}
		}
		if(tag==false){
			Cover(1,x,x);
		}
		PutDown(1,Tn!=1);
		int res=T[1].Cur.maxL;
		if(tag==false){
			Cover(2,x,x);
		}
		return res;
	}
}
int main(){
	int n,q,opt,l,r;
	scanf("%d%d",&n,&q);
	Tree::Init(n);
	SegmentTree::Init(n);
	for(R i=0;i!=q;i++){
		scanf("%d%d",&opt,&l);
		if(opt==3){
			l=SegmentTree::GetAns(l);
			if(l==0){
				puts("-1");
			}else{
				printf("%d\n",l);
			}
		}else{
			scanf("%d",&r);
			SegmentTree::Cover(opt,l,r);
		}
	}
	return 0;
}