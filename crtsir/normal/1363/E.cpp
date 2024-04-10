#include<bits/stdc++.h>
using namespace std;
int n,b[200003],c[200003],cnt[2][200003];
vector<int>v[200003];
long long ans,a[200003];
void dfs(int x,int fa){
	cnt[b[x]][x]+=fabs(b[x]-c[x]);
	if(fa!=-1)a[x]=min(a[x],a[fa]);
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=fa)
			dfs(v[x][i],x),
			cnt[0][x]+=cnt[0][v[x][i]],
			cnt[1][x]+=cnt[1][v[x][i]];
	long long tmp=min(cnt[0][x],cnt[1][x]);
	ans+=tmp*a[x];cnt[0][x]-=tmp;cnt[1][x]-=tmp;
}
int main(){cin>>n;int cnttt=0;
	for(int i=0;i<n;i++)scanf("%lld%d%d",a+i,b+i,c+i),cnttt+=(b[i]-c[i]);
	if(cnttt){cout<<-1;return 0;}
	for(int i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		v[x-1].push_back(y-1);
		v[y-1].push_back(x-1);
	}
	dfs(0,-1);
	cout<<ans*2;
}