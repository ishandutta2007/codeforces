// 228

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<int>fr[N];
int t,n,m,mp[N],ans[N];
int main(){
	for(scanf("%d",&t);t--;){
		fill(mp+1,mp+n+1,0);
		scanf("%d%d",&n,&m);
		for(int i=1,x;i<=m;i++){
			scanf("%d",&x);
			fr[i].resize(x);
			for(int j=0;j<x;j++)
				scanf("%d",&fr[i][j]);
			if(x==1)mp[fr[i][0]]++;
		}int fl=0;
		for(int i=1;i<=n;i++)
			if(mp[i]>(m+1)/2)fl=1;
		if(fl){
			puts("NO");
			continue;
		}puts("YES");
		for(int i=1,x;i<=m;i++)
			printf("%d ",x=fr[i][fr[i].size()==1||mp[fr[i][0]]<(m+1)/2?0:1]),fr[i].size()!=1&&(mp[x]++);
		puts("");
	}
}