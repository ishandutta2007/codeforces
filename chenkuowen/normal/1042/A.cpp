#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	int n,m,mx=0; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int key; scanf("%d",&key);
		mx=max(mx,key);
		q.push(key);
	}
	for(int i=1;i<=m;++i){
		int x=q.top(); q.pop();
		q.push(x+1);
	}
	int ans=0;
	while(!q.empty()) ans=max(ans,q.top()),q.pop(); 
	printf("%d %d\n",ans,mx+m);
	return 0;
}