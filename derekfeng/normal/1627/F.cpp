#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int F[505][505],G[505][505];
int dis[505][505];
void solve_test(){
	int n,K;
	for(int i=0;i<=K;i++)for(int j=0;j<=K;j++)F[i][j]=G[i][j]=0;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++){
		int A,B,C,D;scanf("%d%d%d%d",&A,&B,&C,&D);
		if(abs(A-C)==1){
			if(A>C)swap(A,C);
			F[A][B-1]++,F[K-A][K-(B-1)-1]++;
		}
		if(abs(B-D)==1){
			if(B>D)swap(B,D);
			G[A-1][B]++,G[K-(A-1)-1][K-B]++;
		}
	}
	priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > >pq;
	for(int i=0;i<=K;i++)for(int j=0;j<=K;j++)dis[i][j]=1e9;
	dis[0][0]=0,pq.push({0,{0,0}});
	while(!pq.empty()){
		auto u=pq.top();pq.pop();
		int w=u.fi;pii t=u.se;
		if(w!=dis[t.fi][t.se])continue;
		int w1;pii tt;
		if(t.se>0){
			tt=t;tt.se--;
			w1=w+F[tt.fi][tt.se];
			if(w1<dis[tt.fi][tt.se]){
				dis[tt.fi][tt.se]=w1;
				pq.push({w1,tt});
			}
		}
		if(t.fi>0){
			tt=t;tt.fi--;
			w1=w+G[tt.fi][tt.se];
			if(w1<dis[tt.fi][tt.se]){
				dis[tt.fi][tt.se]=w1;
				pq.push({w1,tt});
			}
		}
		if(t.se<K){
			tt=t;tt.se++;
			w1=w+F[t.fi][t.se];
			if(w1<dis[tt.fi][tt.se]){
				dis[tt.fi][tt.se]=w1;
				pq.push({w1,tt});
			}
		}
		if(t.fi<K){
			tt=t;tt.fi++;
			w1=w+G[t.fi][t.se];
			if(w1<dis[tt.fi][tt.se]){
				dis[tt.fi][tt.se]=w1;
				pq.push({w1,tt});
			}
		}
	}
	printf("%d\n",n-dis[K/2][K/2]);
}
int main(){
	int t;scanf("%d",&t);
	while(t--)solve_test();
}