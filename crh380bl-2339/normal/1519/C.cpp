#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct node{
	int a,b;
}s[N];
bool cmp(const node&x,const node&y){
	return y.a==x.a?x.b<y.b:x.a<y.a;
}
vector<long long>sum[N];
long long ans[N];
int main(){
	int n,m,T,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			ans[i]=0;
			while(!sum[i].empty())sum[i].pop_back();
		}
		for(i=1;i<=n;++i){
			scanf("%d",&s[i].a);
		}
		for(i=1;i<=n;++i)scanf("%d",&s[i].b);
		sort(s+1,s+1+n,cmp);
		for(i=1;i<=n;++i)sum[s[i].a].push_back(s[i].b);
		for(i=1;i<=n;++i){
			m=sum[i].size();
			for(j=1;j<m;++j)sum[i][j]+=sum[i][j-1];
		}
		for(i=1;i<=n;++i){
			m=sum[i].size();
			for(j=1;j<=m;++j){
				k=m%j;
				ans[j]+=sum[i][m-1];
				if(k>=1)ans[j]-=sum[i][k-1];
			}
		}
		for(i=1;i<=n;++i){
			printf("%lld",ans[i]);
			if(i!=n)printf(" ");
			else puts("");
		}
	}
	return 0;
}