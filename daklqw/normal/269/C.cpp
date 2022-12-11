#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 400010
struct _{
	int to,val;
	void s(int a,int b){to=a,val=b;}
}edges[MAXN];
vector<int>grap[MAXN];bool flag[MAXN],vis[MAXN];
int n,m,t1,t2,t3,flows[MAXN],rec[MAXN];
queue<int>q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d %d %d",&t1,&t2,&t3);
		edges[i<<1].s(t2,t3);edges[i<<1|1].s(t1,t3);
		grap[t1].push_back(i<<1);
		grap[t2].push_back(i<<1|1);
		flows[t1]+=t3;
		flows[t2]+=t3;
	}
	q.push(1);vis[1]=true;
	while(!q.empty()){
		int t=q.front();q.pop();
		for(int i=0;i<grap[t].size();++i){
			int idx=grap[t][i],v=edges[idx].to;
			if(!vis[v]){
				rec[v]+=edges[idx].val;
				if(rec[v]==flows[v]>>1&&v<n)q.push(v),vis[v]=true;
				flag[idx>>1]=idx&1;
			}
		}
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",flag[i]);
	return 0;
}