#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> G[200005];
struct Node{
	int x,y,id;
}A[200005];
bool cmp1(Node a,Node b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool cmp2(Node a,Node b){return a.y<b.y||(a.y==b.y&&a.x<b.x);}

int clr[200005];
bool ans=1;
void dfs(int x){
	for(int i=0;i<G[x].size();i++)
		if(!clr[G[x][i]]) clr[G[x][i]]=(clr[x]==1?2:1),dfs(G[x][i]);
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d%d",&A[i].x,&A[i].y),A[i].id=i;
	sort(A+1,A+N+1,cmp1);
	for(int i=1;i<N;i++) if(A[i].x==A[i+1].x)
		G[A[i].id].push_back(A[i+1].id),G[A[i+1].id].push_back(A[i].id),i++;
	sort(A+1,A+N+1,cmp2);
	for(int i=1;i<N;i++) if(A[i].y==A[i+1].y)
		G[A[i].id].push_back(A[i+1].id),G[A[i+1].id].push_back(A[i].id),i++;
	for(int i=1;i<=N;i++){
		if(!clr[i]) dfs(i);
		if(clr[i]==1) printf("r");
		else printf("b");
	}
}