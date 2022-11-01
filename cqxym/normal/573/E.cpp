#include<stdio.h>
#define R register int
#define L long long
#define I inline
#define N 100001
class SplayTree{
	int Size[N],Child[N][2],Par[N],Root,Nodect;
	L Lazy[N],Delta[N];
	I bool Identity(int x){
		return x==Child[Par[x]][1];
	}
	I void GetNode(int&x){
		Nodect++;
		x=Nodect;
	}
	I void PutDown(int p){
		if(p!=0&&Lazy[p]!=0){
			Delta[p]+=Lazy[p];
			Lazy[Child[p][0]]+=Lazy[p];
			Lazy[Child[p][1]]+=Lazy[p];
			Lazy[p]=0;
		}
	}
	I void Refresh(int p){
		Size[p]=Size[Child[p][0]]+Size[Child[p][1]]+1;
	}
	I void Rotate(int x){
		int p=Par[x];
		bool c=Identity(x)^true;
		Par[x]=Par[p];
		Child[Par[x]][Identity(p)]=x;
		Par[p]=x;
		Child[p][c^true]=Child[x][c];
		Par[Child[x][c]]=p;
		Child[x][c]=p;
		Refresh(p);
		Refresh(x);
	}
	I void Splay(int x){
		while(Par[x]!=0){
			int p=Par[x];
			PutDown(Par[p]);
			PutDown(p);
			PutDown(x);
			if(Par[p]!=0){
				Rotate(Identity(x)==Identity(p)?p:x);
			}
			Rotate(x);
		}
		Root=x;
	}
	I int FindNode(int v){
		int res=0,p=Root,preS=0;
		while(p!=0){
			PutDown(p);
			if(Delta[p]>(1ll+preS+Size[Child[p][0]])*v){
				res=p;
				preS+=Size[Child[p][0]]+1;
				p=Child[p][1];
			}else{
				p=Child[p][0];
			}
		}
		return res;
	}
	I void DFS(int x,L&preS,L&ans){
		PutDown(x);
		if(Child[x][0]!=0){
			DFS(Child[x][0],preS,ans);
		}
		preS+=Delta[x];
		if(preS>ans){
			ans=preS;
		}
		if(Child[x][1]!=0){
			DFS(Child[x][1],preS,ans);
		}
	}
	public:
		I void Init(int x){
			Nodect=Root=1;
			Delta[1]=x;
		}
		I void Insert(int v){
			int p=FindNode(v);
			if(p==0){
				GetNode(p);
				Child[p][1]=Root;
				Par[Root]=p;
				Root=p;
				Refresh(p);
				Delta[p]=v;
				Lazy[Child[p][1]]+=v;
			}else{
				Splay(p);
				int x;
				GetNode(x);
				Par[Child[p][1]]=x;
				Child[x][1]=Child[p][1];
				Child[p][1]=x;
				Par[x]=p;
				Refresh(x);
				Refresh(p);
				Lazy[Child[x][1]]+=v;
				Delta[x]=(2ll+Size[Child[p][0]])*v;
			}
		}
		I void Print(){
			L preS=0,ans=0;
			DFS(Root,preS,ans);
			printf("%lld",ans);
		}
}T;
int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	T.Init(x);
	for(R i=1;i!=n;i++){
		scanf("%d",&x);
		T.Insert(x);
	}
	T.Print();
	return 0;
}