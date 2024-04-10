#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define R register int
#define V vector<int>::iterator
#define N 500001
vector<int>G1[N],G2[N];
int b[N],w[N],dp[N];
bool vis[N];
inline int Max(int&x,int&y){
	return x>y?x:y;
}
struct Node{
	int Dis,Id;
	inline friend bool operator<(Node x,Node y){
		return x.Dis>y.Dis;
	}
};
int main(){
    int n,m,x,y,z;
    scanf("%d%d",&n,&m);
    for(R i=0;i!=m;i++){
    	scanf("%d%d%d",&x,&y,&z);
    	if(z==0){
    		G1[y].push_back(x);
		}else{
			G2[y].push_back(x);
		}
	}
	priority_queue<Node>Q;
	Node Tem;
	Tem.Dis=0;
	Tem.Id=n;
	Q.push(Tem);
	for(R i=1;i!=n;i++){
		w[i]=b[i]=dp[i]=N;
	}
	while(Q.empty()==false){
		Tem=Q.top();
		Q.pop();
		x=Tem.Id;
		if(vis[x]==false){
			vis[x]=true;
			for(V T=G1[x].begin();T!=G1[x].end();T++){
				if(b[*T]==N){
					b[*T]=dp[x]+1;
					if(Max(b[*T],w[*T])<N){
						Tem.Dis=dp[*T]=Max(b[*T],w[*T]);
						Tem.Id=*T;
						Q.push(Tem);
					}
				}
			}
			for(V T=G2[x].begin();T!=G2[x].end();T++){
				if(w[*T]==N){
					w[*T]=dp[x]+1;
					if(Max(b[*T],w[*T])<N){
						Tem.Dis=dp[*T]=Max(b[*T],w[*T]);
						Tem.Id=*T;
						Q.push(Tem);
					}
				}
			}
		}
	}
	if(dp[1]==N){
		puts("-1");
	}else{
		printf("%d\n",dp[1]);
	}
	for(R i=1;i<=n;i++){
		if(w[i]>b[i]){
			putchar('1');
		}else{
			putchar('0');
		}
	}
    return 0;
}