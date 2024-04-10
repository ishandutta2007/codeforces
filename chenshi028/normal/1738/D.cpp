#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int o=1e5+10;
int T,n,b[o],k;bool vis[o];queue<int> q;vector<int> vec[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),k=0){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) vis[i]=0;
		for(int i=0;i<=n+1;++i) vec[i].clear();
		for(int i=1;i<=n;++i) scanf("%d",&b[i]),vis[b[i]]=1,vec[b[i]].push_back(i);
		for(int i=1;i<=n;++i) if(b[i]>i) k=i;
		q.push(0);q.push(n+1);
		printf("%d\n",k);
		for(int t;!q.empty();q.pop()){
			t=0;
			for(int i=vec[q.front()].size(),j;i--;) if(!vis[j=vec[q.front()][i]]) printf("%d ",j);else t=j;
			if(t) printf("%d ",t),q.push(t);
		}
	}
	return 0;
}