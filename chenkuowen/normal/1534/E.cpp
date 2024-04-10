#include<bits/stdc++.h>
using namespace std;
int query(vector<int> a){
	printf("? ");
	for(auto x:a) printf("%d ",x+1); puts("");
	fflush(stdout);
	int ret; scanf("%d",&ret);
	return ret;
}
void finish(int x){ 
	if(x==-1) puts("-1");
	else printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}
int solve(int n,int k){
	static int f[505],pre[505],vis[505];
	for(int i=0;i<=n;++i) f[i]=(int)1e9,pre[i]=-1,vis[i]=0;
	f[0]=0; 
	for(int t=0;t<=n;++t){
		int x=-1;
		for(int i=0;i<=n;++i)
			if(!vis[i]&&(x==-1||f[i]<f[x])) x=i;
		vis[x]=1;
		for(int j=0;j<=k;++j){
			if(j<=x&&k-j<=n-x){
				int y=x-j+(k-j);
				if(f[x]+1<f[y]) f[y]=f[x]+1,pre[y]=j;
			}
		}
	}
	if(f[n]==(int)1e9) return -1;
	int x=n,ret=0;
	vector<int> s(n,1);
	while(x>0){
		vector<int> a;
		int c1=k-pre[x],c0=pre[x];
//		printf("<%d %d %d>\n",x,c1,c0);
		x=x-c1+c0;
		for(int i=0;i<n;++i){
			if(s[i]&&c1>0) a.push_back(i),--c1;
			if(!s[i]&&c0>0) a.push_back(i),--c0;
		}
		assert(c0==0&&c1==0);
		ret^=query(a);
		for(auto x:a) s[x]^=1;
	}
	return ret;
}
int main(){
	int n,k; scanf("%d%d",&n,&k);
	finish(solve(n,k));
	return 0;
}