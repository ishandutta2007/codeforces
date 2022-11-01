#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 1200001
#define M 20000000
I void Max(int&x,const int y){
	if(x<y){
		x=y;
	}
}
char s[600001];
int pos[500001];
namespace SAM{
	int Par[N],Child[N][27],Len[N],Root[N],Ls[M],Rs[M],MaxS[M],Fa[N][20],Last,Tot,Count,Color;
	vector<int>G[N];
	I void GetNode(int&x){
		Count++;
		x=Count;
	}
	I void Modify(int p,int lf,int rt,const int x){
		MaxS[p]=1;
		if(lf!=rt){
			int mid=lf+rt>>1;
			if(x>mid){
				GetNode(Rs[p]);
				Modify(Rs[p],mid+1,rt,x);
			}else{
				GetNode(Ls[p]);
				Modify(Ls[p],lf,mid,x);
			}
		}
	}
	I int Merge(int x,int y,int lf,int rt){
		if(x==0||y==0){
			return x|y;
		}
		int p;
		GetNode(p);
		if(lf==rt){
			MaxS[p]=MaxS[x]+MaxS[y];
		}else{
			Ls[p]=Merge(Ls[x],Ls[y],lf,lf+rt>>1);
			MaxS[p]=MaxS[Ls[p]];
			Rs[p]=Merge(Rs[x],Rs[y],lf+rt+2>>1,rt);
			Max(MaxS[p],MaxS[Rs[p]]);
		}
		return p;
	}
	I int GetMax(int p,int lf,int rt,const int l,const int r){
		if(l<=lf&&rt<=r){
			return MaxS[p];
		}
		int mid=lf+rt>>1,res=0;
		if(l<=mid&&Ls[p]!=0){
			res=GetMax(Ls[p],lf,mid,l,r);
		}
		if(r>mid&&Rs[p]!=0){
			Max(res,GetMax(Rs[p],mid+1,rt,l,r));
		}
		return res;
	}
	I int FindMin(int p,int lf,int rt,const int l,const int r,const int d){
		if(MaxS[p]<d){
			return 0;
		}
		if(lf==rt){
			return lf;
		}
		int mid=lf+rt>>1,res=0;
		if(l<=mid){
			res=FindMin(Ls[p],lf,mid,l,r,d);
		}
		if(res!=0){
			return res;
		}
		return FindMin(Rs[p],mid+1,rt,l,r,d);
	}
	I void InitSAM(const int m){
		Color=m;
		Last=Tot=1;
	}
	I int Insert(int x,int c){
		Tot++;
		int p=Last,cur=Tot;
		GetNode(Root[cur]);
		if(x!=0){
			Modify(Root[cur],1,Color,x);
		}
		Last=Tot;
		Len[Tot]=Len[p]+1;
		while(p!=0&&Child[p][c]==0){
			Child[p][c]=cur;
			p=Par[p];
		}
		if(p==0){
			Par[cur]=1;
		}else{
			int q=Child[p][c];
			if(Len[p]+1==Len[q]){
				Par[cur]=q;
			}else{
				Tot++;
				int nq=Tot;
				GetNode(Root[nq]);
				Len[nq]=Len[p]+1;
				for(R i=0;i!=27;i++){
					Child[nq][i]=Child[q][i];
				}
				Par[nq]=Par[q];
				Par[q]=Par[cur]=nq;
				while(Child[p][c]==q&&p!=0){
					Child[p][c]=nq;
					p=Par[p];
				}
			}
		}
		return Last;
	}
	I void DFS(int p){
		for(R i=1;Fa[p][i-1]!=0;i++){
			Fa[p][i]=Fa[Fa[p][i-1]][i-1];
		}
		for(int T:G[p]){
			Fa[T][0]=p;
			DFS(T);
			Root[p]=Merge(Root[p],Root[T],1,Color);
		}
	}
	I void InitTree(){
		for(int i=2;i<=Tot;i++){
			G[Par[i]].push_back(i);
		}
		DFS(1);
	}
	I int FindString(int r,int l){
		for(R i=19;i!=-1;i--){
			if(Fa[r][i]!=0&&Len[Fa[r][i]]>=l){
				r=Fa[r][i];
			}
		}
		return r;
	}
	I int SolveMax(int x,int l,int r){
		return GetMax(Root[x],1,Color,l,r);
	}
	I int SolveMin(int x,int l,int r,int d){
		return FindMin(Root[x],1,Color,l,r,d);
	}
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),m,q,l,r,pl,pr,x,d;
	scanf("%d",&m);
	SAM::InitSAM(m);
	for(R i=1;i<=n;i++){
		pos[i]=SAM::Insert(0,s[i]-'a');
	}
	for(R i=1;i<=m;i++){
		SAM::Insert(0,26);
		scanf("%s",s);
		n=strlen(s);
		for(R j=0;j!=n;j++){
			SAM::Insert(i,s[j]-'a');
		}
	}
	SAM::InitTree();
	scanf("%d",&q);
	for(R i=0;i!=q;i++){
		scanf("%d%d%d%d",&l,&r,&pl,&pr);
		x=SAM::FindString(pos[pr],pr-pl+1);
		d=SAM::SolveMax(x,l,r);
		printf("%d %d\n",SAM::SolveMin(x,l,r,d),d);
	}
	return 0;
}