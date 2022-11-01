#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
#define I inline
struct Edge{
	int Start,End,Len;
	I friend bool operator<(Edge A,Edge B){
		return A.Len<B.Len;
	}
}e[400];
int f[200001];
L dis[401][401];
I int GetF(int x){
	if(f[x]==x){
		return x;
	}
	f[x]=GetF(f[x]);
	return f[x];
}
vector<int>S[200001];
I void Floyd(int x,const int m,vector<L>&D){
	map<int,int>Q;
	int n=S[x].size();
	for(R i=0;i!=n;i++){
		Q[S[x][i]]=i;
		for(R j=0;j!=n;j++){
			dis[i][j]=999999999999;
		}
		dis[i][i]=0;
	}
	for(R i=0;i!=m;i++){
		if(Q.count(e[i].End)!=0){
			int x=Q[e[i].Start],y=Q[e[i].End];
			dis[x][y]=dis[y][x]=e[i].Len;
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=n;j++){
			const L d=dis[j][i];
			for(R k=0;k!=n;k++){
				if(dis[j][k]>d+dis[i][k]){
					dis[j][k]=d+dis[i][k];
				}
			}
		}
	}
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			D.push_back(dis[i][j]);
		}
	}
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	Edge Tem;
	priority_queue<Edge>Q;
	for(R i=0;i!=m;i++){
		scanf("%d%d%d",&Tem.Start,&Tem.End,&Tem.Len);
		if(Q.size()<k){
			Q.push(Tem);
		}else if(Tem<Q.top()){
			Q.pop();
			Q.push(Tem);
		}
	}
	for(R i=1;i<=n;i++){
		f[i]=i;
	}
	for(R i=0;i!=k;i++){
		e[i]=Q.top();
		Q.pop();
		if(GetF(e[i].Start)!=GetF(e[i].End)){
			f[f[e[i].Start]]=e[i].End;
		}
	}
	for(int i=1;i<=n;i++){
		S[GetF(i)].push_back(i);
	}
	vector<L>D;
	for(R i=1;i<=n;i++){
		if(S[i].size()>1){
			Floyd(i,k,D);
		}
	}
	nth_element(D.begin(),D.begin()+k-1,D.end());
	printf("%lld",D[k-1]);
	return 0;
}