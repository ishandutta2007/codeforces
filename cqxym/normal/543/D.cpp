#include<stdio.h>
#include<vector>
using namespace std;
#define L long long
#define I inline
#define N 200001
#define P 1000000007
vector<int>G[N];
int f[N][2],ans[N];
I void PreDP(int x){
	f[x][0]=f[x][1]=1;
	for(vector<int>::iterator T=G[x].begin();T!=G[x].end();T++){
		PreDP(*T);
		f[x][0]=(L)f[x][0]*f[*T][0]%P;
		f[x][1]=(L)f[x][1]*(f[*T][0]+f[*T][1])%P;
	}
}
I void ReDP(int x,int F){
	ans[x]=f[x][1];
	if(G[x].empty()==false){
		vector<int>S[2][2];
		S[0][0].push_back(f[G[x][0]][0]);
		S[0][1].push_back(f[G[x][0]][0]+f[G[x][0]][1]);
		for(vector<int>::iterator T=G[x].begin()+1;T!=G[x].end();T++){
			S[0][0].push_back((L)S[0][0].back()*f[*T][0]%P);
			S[0][1].push_back((L)S[0][1].back()*(f[*T][0]+f[*T][1])%P);
		}
		S[1][0].push_back(f[G[x].back()][0]);
		S[1][1].push_back(f[G[x].back()][0]+f[G[x].back()][1]);
		for(vector<int>::reverse_iterator T=G[x].rbegin()+1;T!=G[x].rend();T++){
			S[1][0].push_back((L)S[1][0].back()*f[*T][0]%P);
			S[1][1].push_back((L)S[1][1].back()*(f[*T][0]+f[*T][1])%P);
		}
		int s=G[x].size();
		for(register int i=0;i!=s;i++){
			f[x][0]=f[F][0];
			f[x][1]=f[F][0]+f[F][1];
			if(i!=0){
				f[x][0]=(L)f[x][0]*S[0][0][i-1]%P;
				f[x][1]=(L)f[x][1]*S[0][1][i-1]%P;
			}
			if(i!=s-1){
				f[x][0]=(L)f[x][0]*S[1][0][s-i-2]%P;
				f[x][1]=(L)f[x][1]*S[1][1][s-i-2]%P;
			}
			f[G[x][i]][0]=(L)f[G[x][i]][0]*f[x][0]%P;
			f[G[x][i]][1]=(L)f[G[x][i]][1]*(f[x][0]+f[x][1])%P;
			ReDP(G[x][i],x);
		}
	}
}
int main(){
	int n,p;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		G[p].push_back(i);
	}
	PreDP(1);
	f[0][0]=1;
	ReDP(1,0);
	for(register int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}