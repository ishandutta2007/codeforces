#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 4000
#define P 1000000007
typedef int State[8001];
I void Add(int&x,const int y){
	x+=y;
	if(x>=P){
		x-=P;
	}
}
int Last[2001],Next[8004],End[8004],ct;
bool vis[8004];
I void Link(int x,int y){
	ct++;
	End[ct]=y;
	Next[ct]=Last[x];
	Last[x]=ct;
}
vector<int>C;
I void DFS(int x,int dis){
	for(R i=Last[x];i!=0;i=Next[i]){
		if(vis[i]==false){
			if(End[i]==1){
				C.push_back(dis);
			}else{
				vis[i]=vis[i^1]=true;
				DFS(End[i],dis+1);
			}
		}
	}
}
I void Insert(State A,int x,const int n){
	static State B;
	for(R i=-n;i<=n;i++){
		B[i+N]=A[i+N];
	}
	for(R i=-n;i<=n;i++){
		if(A[i+N]!=0){
			if(x-i<=n){
				Add(B[i-x+N],A[i+N]);
			}
			if(i+x<=n){
				Add(B[i+x+N],A[i+N]);
			}
		}
	}
	for(R i=-n;i<=n;i++){
		A[i+N]=B[i+N];
	}
}
I void Append(State A,const int x,const int n){
	static State B;
	for(R i=-n;i<=n;i++){
		B[i+N]=0;
	}
	for(R i=-n;i<=n;i++){
		if(A[i+N]!=0){
			if(x-i<=n){
				Add(B[i-x+N],A[i+N]);
			}
			if(i+x<=n){
				Add(B[i+x+N],A[i+N]);
			}
		}
	}
	for(R i=-n;i<=n;i++){
		A[i+N]=B[i+N];
	}
}
I void DivAndConq(int l,int r,State F,State G,int&ans,int n){
	if(l==r){
		if(C[l]>1){
			int del=C[r]-2;
			for(R i=1;i<=del;i++){
				ans=(4ll*F[i+N]+ans)%P;
			}
			ans=(4ll*G[N-del-1]+(F[N]<<1)+ans)%P;
		}
		if(l==0){
			Append(G,C[0],n);
			Add(ans,G[N]);
		}
	}else{
		int mid=l+r>>1,n2=0;
		for(R i=r;i!=mid;i--){
			n2+=C[i];
		}
		State G2,F2;
		for(R i=-n;i<=n;i++){
			F2[i+N]=F[i+N];
			G2[i+N]=G[i+N];
		}
		for(R i=l;i<=mid;i++){
			Insert(F2,C[i],n);
			Append(G2,C[i],n);
		}
		for(R i=r;i!=mid;i--){
			Insert(F,C[i],n);
			Append(G,C[i],n);
		}
		n-=n2;
		DivAndConq(l,mid,F,G,ans,n);
		DivAndConq(mid+1,r,F2,G2,ans,n2);
	}
}
I void Solve(){
	DFS(1,1);
	if(C.empty()==true){
		puts("1");
		return;
	}
	int ans=0,n=0;
	State F,G;
	for(auto T:C){
		n+=T;
	}
	for(R i=-n;i<=n;i++){
		F[i+N]=G[i+N]=0;
	}
	F[N]=G[N]=1;
	DivAndConq(0,C.size()-1,F,G,ans,n);
	printf("%d\n",ans);
}
int main(){
	int n,m,x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		ct=1;
		for(R i=1;i<=n;i++){
			Last[i]=0;
		}
		for(R i=0;i!=m;i++){
			scanf("%d%d",&x,&y);
			Link(x,y);
			Link(y,x);
		}
		for(R i=2;i<=ct;i++){
			vis[i]=false;
		}
		C.clear();
		Solve();
	}
	return 0;
}