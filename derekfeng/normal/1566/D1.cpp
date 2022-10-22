#include<bits/stdc++.h>
using namespace std;
int T,n,m,N;
vector<int>all,ord[100000];
int a[100000],c[100000];
bool vis[305][305];
void solve(){
	all.clear();
	cin>>n>>m;
	for(int i=0;i<=n*m;i++)c[i]=0,ord[i].clear();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)vis[i][j]=0;
	for(int i=0;i<n*m;i++)cin>>a[i],all.push_back(a[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());N=all.size();
	for(int i=0;i<n*m;i++)a[i]=lower_bound(all.begin(),all.end(),a[i])-all.begin()+1,c[a[i]]++;
	int C=0;
	for(int i=1;i<=N;i++){
		for(int r=(C+1+m-1)/m;r<=(C+c[i]+m-1)/m;r++){
			int L,R;
			if(C+1<=(r-1)*m+1)L=1;
			else L=(C+1)-(r-1)*m;
			if(r*m<=C+c[i])R=m;
			else R=(C+c[i])-(r-1)*m;
			for(int j=R;j>=L;j--)ord[i].push_back((r-1)*m+j);
		}
		reverse(ord[i].begin(),ord[i].end());
		C+=c[i];
	}
	int ans=0;
	for(int i=0;i<n*m;i++){
		int p=ord[a[i]].back();ord[a[i]].pop_back();
		int x=(p+m-1)/m,y=p-(x-1)*m;
		for(int j=1;j<y;j++)if(vis[x][j])ans++;
		vis[x][y]=1;
	}
	cout<<ans<<"\n";
}
int main(){
	cin>>T;
	while(T--)solve();
}