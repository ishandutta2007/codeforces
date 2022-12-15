#include<bits/stdc++.h>
using namespace std;

int R,C,N,K;
struct Node{
	int x,y;
	bool operator<(const Node b)const{
		return y<b.y||(y==b.y&&x<b.x);
	}
}A[3005],B[3005];
int l[3005],r[3005],len;
int cnt[3005];
long long ANS;
long long tmp=0;
vector<int> G[3005];

void DFS(int x,int k){
	tmp-=B[x].y*cnt[x];
	tmp+=B[l[x]].y*cnt[x];
	if(l[x]&&k>1) DFS(l[x],k-1);
	if(l[x]) cnt[l[x]]+=cnt[x];
	cnt[x]=0;
}
void debug(int u,int v){
	printf("[%d,%d] :\n",u,v);
	for(int i=1;i<=len;i++) printf("%d ",cnt[i]);printf("\n");
}

int main(){
	scanf("%d%d%d%d",&R,&C,&N,&K);
	for(int i=1;i<=N;i++) scanf("%d%d",&A[i].x,&A[i].y);
	sort(A+1,A+N+1);
	for(int u=1;u<=R;u++){
		int v=R;
		len=0;
		for(int i=1;i<=R;i++) G[i].clear();
		for(int i=1;i<=N;i++) if(A[i].x>=u) B[++len]=A[i],l[len]=len-1,r[len]=len+1,cnt[len]=0,G[B[len].x].push_back(len);
		tmp=0;
		for(int i=1,j=0;i<=C;i++){
			while(j+1<=len&&B[j+1].y<=i) j++;
			if(j-K+1>0) cnt[j-K+1]++,tmp+=B[j-K+1].y;
		}
		ANS+=tmp;
//		debug(u,v);
		while(v>u){
			for(int i=0;i<G[v].size();i++){
				int c=G[v][i];
				DFS(c,K);
				r[l[c]]=r[c],l[r[c]]=l[c];
			}
			ANS+=tmp;
			v--;
//			debug(u,v);
		}
	}
	printf("%lld\n",ANS);
}