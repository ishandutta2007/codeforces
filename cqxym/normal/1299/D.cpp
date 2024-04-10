#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
#define R register int
#define I inline
#define N 100001
#define P 1000000007
I void Add(int&x,const int y){
	x+=y;
	if(x>=P){
		x-=P;
	}
}
struct Edge{
	int End,Len;
};
vector<Edge>G[N],H[N];
int f[N],st[N],ed[N],len[N],bel[N],ord[N],dis[N],sec[N],trans[400][400],dp[2][400],tot;
bool tag[N],chose[N];
I int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
I void PreDFS(int x,const int t){
	bel[x]=t;
	for(vector<Edge>::iterator T=G[x].begin();T!=G[x].end();T++){
		int v=T->End;
		if(v!=1&&bel[v]==0){
			PreDFS(v,t);
		}
	}
}
I void ReDFS(int x,int F){
	for(vector<Edge>::iterator T=H[x].begin();T!=H[x].end();T++){
		int v=T->End;
		if(v!=F){
			dis[v]=dis[x]^T->Len;
			ReDFS(v,x);
		}
	}
}
struct Basis{
	int val[5];
	I void Init(int x){
		val[0]=x&1;
		val[1]=x>>1&3;
		val[2]=x>>3&7;
		val[3]=x>>6&15;
		val[4]=x>>10&31;
	}
	I bool Insert(int x){
		for(R i=4;i!=-1;i--){
			if ((x&1<<i)!=0){
				if(val[i]!=0){
					x^=val[i];
				}else{
					val[i]=x;
					for(R j=0;j!=i;j++){
						if(val[j]!=0&&(val[i]&1<<j)!=0){
							val[i]^=val[j];
						}
					}
					for(R j=i+1;j!=5;j++){
						if((val[j]&1<<i)!=0){
							val[j]^=val[i];
						}
					}
					return true;
				}
			}
		}
		return false;
	}
	I int Hash(){
		return val[0]|val[1]<<1|val[2]<<3|val[3]<<6|val[4]<<10;
	}
}b[N];
map<int,int>Q;
I void DFS(Basis B){
	int t=B.Hash();
	if(Q.count(t)==false){
		tot++;
		Q[t]=tot;
		ord[tot]=t;
		for(R i=1;i!=32;i++){
			Basis C=B;
			if(C.Insert(i)==true){
				DFS(C);
			}
		}
	}
}
I void InitTrans(){
	Basis A,B;
	A.Init(0);
	DFS(A);
	for(R i=1;i<=tot;i++){
		A.Init(ord[i]);
		for(R j=1;j<=tot;j++){
			B.Init(ord[j]);
			bool f=true;
			for(R k=0;k!=5;k++){
				if(A.val[k]!=0&&B.Insert(A.val[k])==false){
					f=false;
					break;
				}
			}
			if(f==true){
				trans[i][j]=Q[B.Hash()];
			}
		}
	}
}
int main(){
	int n,m,x,ct=0;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=m;i++){
		scanf("%d%d%d",st+i,ed+i,len+i);
		Edge Tem;
		Tem.Len=len[i];
		Tem.End=ed[i];
		G[st[i]].push_back(Tem);
		Tem.End=st[i];
		G[ed[i]].push_back(Tem);
	}
	for(R i=1;i<=n;i++){
		f[i]=i;
	}
	for(vector<Edge>::iterator T=G[1].begin();T!=G[1].end();T++){
		x=T->End;
		f[x]=1;
		H[1].push_back(*T);
		Edge Tem=*T;
		Tem.End=1;
		H[x].push_back(Tem);
		tag[x]=true;
		if(bel[x]==0){
			ct++;
			PreDFS(x,ct);
		}
	}
	for(R i=0;i!=m;i++){
		if(GetF(st[i])!=GetF(ed[i])){
			f[f[st[i]]]=ed[i];
			Edge Tem;
			Tem.Len=len[i];
			Tem.End=ed[i];
			H[st[i]].push_back(Tem);
			Tem.End=st[i];
			H[ed[i]].push_back(Tem);
		}else if(st[i]!=1&&ed[i]!=1){
			chose[i]=true;
		}
	}
	ReDFS(1,0);
	for(R i=1;i<=ct;i++){
		sec[i]=-1;
	}
	InitTrans();
	for(R i=0;i!=m;i++){
		if(chose[i]==true){
			int l=bel[st[i]];
			if(tag[st[i]]==true&&tag[ed[i]]==true){
				if(sec[l]==-1){
					sec[l]=dis[st[i]]^dis[ed[i]]^len[i];
				}
			}else if(b[l].Insert(dis[st[i]]^dis[ed[i]]^len[i])==false){
				sec[l]=-2;
			}
		}
	}
	Basis A;
	A.Init(0);
	dp[0][Q[A.Hash()]]=1;
	int lt=0;
	for(R i=1;i<=ct;i++){
		if(sec[i]!=-2){
			lt++;
			for(R j=1;j<=tot;j++){
				dp[lt&1][j]=dp[1^lt&1][j];
			}
			int d=Q[b[i].Hash()];
			for(R j=1;j<=tot;j++){
				Add(dp[lt&1][trans[d][j]],dp[1^lt&1][j]);
			}
			if(sec[i]!=-1){
				for(R j=1;j<=tot;j++){
					Add(dp[lt&1][trans[d][j]],dp[1^lt&1][j]);
				}
				if(b[i].Insert(sec[i])==true){
					int d2=Q[b[i].Hash()];
					for(R j=1;j<=tot;j++){
						Add(dp[lt&1][trans[d2][j]],dp[1^lt&1][j]);
					}
				}
			}
		}
	}
	int ans=0;
	for(R i=1;i<=tot;i++){
		Add(ans,dp[lt&1][i]);
	}
	printf("%d",ans);
	return 0;
}