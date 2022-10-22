#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
const int o=2e5+10;
int T,n,p[o],d[o],l[o],r[o],ans;long long R[o];queue<int> q;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0){
		scanf("%d",&n);
		for(int i=2;i<=n;++i) scanf("%d",&p[i]),++d[p[i]];
		for(int i=1;i<=n;++i) scanf("%d%d",&l[i],&r[i]);
		for(int i=1;i<=n;R[i++]=0) if(!d[i]) q.push(i);
		for(int u;!q.empty();q.pop()){
			u=q.front();
			if(R[u]<l[u]) R[u]=r[u],++ans;
			R[p[u]]+=min(R[u],r[u]+0ll);
			if(!--d[p[u]]) q.push(p[u]);
		}
	}
	return 0;
}