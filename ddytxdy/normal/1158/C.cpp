#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+50;
int t,n,a[N],b[N],now,stck[N],tp;
vector<int>v[N];
void dfs(int x){
	for(int i=0;i<v[x].size();i++){
		b[v[x][i]]=now--;
		dfs(v[x][i]);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]==-1)a[i]=i+1;
			v[a[i]].push_back(i);
		}
		now=n;
		dfs(n+1);bool flag=0;b[n+1]=1e9;
		for(int i=1;i<=n+1;i++){
			while(tp&&b[stck[tp]]<b[i]){
				if(a[stck[tp]]!=i){
					puts("-1");flag=1;
				}
				tp--;
				if(flag)break;
			}
			if(flag)break;
			stck[++tp]=i;
		}
		if(!flag){
			for(int i=1;i<=n;i++)printf("%d ",b[i]);
			puts("");
		}
		tp=0;
		for(int i=1;i<=n+1;i++)v[i].clear();
	}
	return 0;
}