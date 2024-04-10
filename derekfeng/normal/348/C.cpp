#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=514;
int n,m,q,a[100004];
int d[100004];
vector<int>S[100004];vector<ll>bt[100004];
int id[100004],cnt,Big[100004];
int bit[203][100004];
ll ans[100004],cur[100004];
ll lzy[203],hvp[203][100004];
char buf[3];
int x,K;
vector<int>v[100004];
void upd(){
	scanf("%d%d",&x,&K);
	for(int i=1;i<=cnt;i++)ans[Big[i]]+=1ll*K*bit[i][x];
	if(d[x]>M)lzy[id[x]]+=K;
	else for(auto y:S[x])cur[y]+=K;
}
void ask(){
	scanf("%d",&x);
	if(d[x]>M){
		printf("%I64d\n",ans[x]);
		return;
	}
	for(int i=0;i<d[x];i++){
		ans[x]+=cur[S[x][i]]-bt[x][i];
		bt[x][i]=cur[S[x][i]];
	}
	for(int i=1;i<=cnt;i++){
		ans[x]+=(lzy[i]-hvp[i][x])*bit[i][x];
		hvp[i][x]=lzy[i];
	}
	printf("%I64d\n",ans[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&d[i]);S[i].resize(d[i]),bt[i].resize(d[i],0); 
		if(d[i]>M)id[i]=++cnt,Big[cnt]=i;
		for(int j=0;j<d[i];j++)scanf("%d",&S[i][j]),ans[i]+=a[S[i][j]],v[S[i][j]].push_back(i);
	}
	for(int i=1;i<=cnt;i++)
		for(auto x:S[Big[i]])for(auto y:v[x])bit[i][y]++;
	while(q--){
		scanf("%s",buf);
		if(*buf=='+')upd();
		else ask();
	}
}