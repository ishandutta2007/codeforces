#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e3+5,Inf=1e9;
int n,m,cnt[N],ans=Inf;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),cnt[x]++;
	for(int i=1;i<=n;i++)ans=min(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}