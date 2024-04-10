#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define L long long
#define I inline
#define N 200001
#define P 998244353
I int PowMod(int x,int y){
	int res=1;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
struct Edge{
	int End,Rx,Ry;
};
I Edge Pair(int y,int a,int b){
	Edge Res;
	Res.End=y;
	Res.Rx=a;
	Res.Ry=b;
	return Res;
}
vector<Edge>G[N];
bool vis[N];
int prime[17984],book[N],rate[N];
namespace Counter{
	int Ct[17984],MaxC[17984];
	I void Clear(const int n){
		for(R i=0;i!=n;i++){
			Ct[i]=MaxC[i]=0;
		}
	}
	I void Modify(int x,int d){
		Ct[x]+=d;
		if(Ct[x]>MaxC[x]){
			MaxC[x]=Ct[x];
		}
	}
}
I void DFS(int x,int F){
	for(Edge T:G[x]){
		int v=T.End;
		if(v!=F){
			//printf("V%d %d %d %d\n",x,v,T.Rx,T.Ry);
			rate[v]=(L)rate[x]*T.Rx%P*PowMod(T.Ry,P-2)%P;
			vector<int>A,B;
			int q=T.Ry;
			while(q!=1){
				A.push_back(book[q]);
				q/=prime[book[q]];
			}
			q=T.Rx;
			while(q!=1){
				B.push_back(book[q]);
				q/=prime[book[q]];
			}
			//printf("Y%d\n",T.Ry);
			for(int T:A){
				//printf("T%d\n",T);
				Counter::Modify(T,1);
			}
			for(int T:B){
				Counter::Modify(T,-1);
			}
			DFS(v,x);
			for(int T:A){
				Counter::Modify(T,-1);
			}
			for(int T:B){
				Counter::Modify(T,1);
			}
		}
	}
}
I int Gcd(int x,int y){
	return y==0?x:Gcd(y,x%y);
}
I void Solve(){
	int n,x,y,a,b,t=0;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		vector<Edge>().swap(G[i]);
		vis[i]=false;
	}
	for(R i=2;i<=n;i++){
		if(vis[i]==false){
			book[i]=t;
			prime[t]=i;
			t++;
		}
		for(R j=0;i*prime[j]<=n;j++){
			vis[i*prime[j]]=true;
			book[i*prime[j]]=j;
			if(i%prime[j]==0){
				break;
			}
		}
	}
	Counter::Clear(t);
	for(R i=1;i!=n;i++){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		int g=Gcd(a,b);
		a/=g;
		b/=g;
		G[x].push_back(Pair(y,b,a));
		G[y].push_back(Pair(x,a,b));
	}
	DFS(1,0);
	/*for(R i=1;i<=n;i++){
		printf("%d ",rate[i]);
	}
	puts("");*/
	int sum=0;
	for(R i=1;i<=n;i++){
		sum+=rate[i];
		if(sum>=P){
			sum-=P;
		}
	}
	for(R i=0;i!=t;i++){
		//printf("I%d %d %d %d\n",i,prime[i],Counter::MaxC[i],PowMod(prime[i],Counter::MaxC[i]));
		sum=(L)sum*PowMod(prime[i],Counter::MaxC[i])%P;
	}
	printf("%d\n",sum);
}
int main(){
	rate[1]=1;
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}