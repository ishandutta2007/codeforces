#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200004];
int s[2][7000000],cnt;
int L[7000000],R[7000000];
void ins(int x,int id){
	int cur=0;
	for(int i=29;~i;i--){
		if(!L[cur])L[cur]=id;R[cur]=id;
		int stat=(x>>i)&1;
		if(!s[stat][cur])s[stat][cur]=++cnt;
		cur=s[stat][cur];
	}
}
int qry(int x,int a,int dep){
	if(dep<0)return 0;
	int stat=(a>>dep)&1;
	if(s[stat][x])return qry(s[stat][x],a,dep-1);
	return qry(s[stat^1][x],a,dep-1)+(1<<dep);
}
ll dfs(int x,int dep){
	if(dep<0)return 0;
	if(s[0][x]&&s[1][x]){
		int ans=(1<<30);
		for(int i=L[s[0][x]];i<=R[s[0][x]];i++)ans=min(ans,qry(s[1][x],a[i],dep-1)+(1<<dep));
		return dfs(s[0][x],dep-1)+dfs(s[1][x],dep-1)+ans;
	}else if(s[0][x])return dfs(s[0][x],dep-1);
	else if(s[1][x])return dfs(s[1][x],dep-1);
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);m=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=m;i++)ins(a[i],i);
	printf("%I64d",dfs(0,29));
}