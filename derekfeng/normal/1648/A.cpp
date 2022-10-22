#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
ll ans;
int n,m;
vector<int>c[100004],d[100004];
void sol(int col){
	sort(c[col].begin(),c[col].end());
	sort(d[col].begin(),d[col].end());
	int num=0;ll s=0;
	for(int i=0;i<c[col].size();i++){
		int u=c[col][i],v=d[col][i];
		ans+=(ll)num*(u+v)-s;
		num++,s+=u+v;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		int t;scanf("%d",&t);
		c[t].push_back(i),d[t].push_back(j);
	}
	for(int i=1;i<=1e5;i++)sol(i);
	printf("%lld",ans);
}