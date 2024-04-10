#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int T,n,m;
int pre1[500005],pre2[500005],suf1[500005],suf2[500005];
char ans[500005];
void sol(){
	vector<vector<int> >a,mx_pre,mx_suf,mn_pre,mn_suf;
	scanf("%d%d",&n,&m);
	a.resize(n+1);
	mx_pre.resize(n+1);
	mx_suf.resize(n+1);
	mn_pre.resize(n+1);
	mn_suf.resize(n+1);
	for(int i=1;i<=n;i++){
		a[i].resize(m+2);
		mx_pre[i].resize(m+2,0);
		mx_suf[i].resize(m+2,0);
		mn_pre[i].resize(m+2,1e9);
		mn_suf[i].resize(m+2,1e9);
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mx_pre[i][j]=max(mx_pre[i][j-1],a[i][j]);
			mn_pre[i][j]=min(mn_pre[i][j-1],a[i][j]);
		}
		for(int j=m;j;j--){
			mx_suf[i][j]=max(mx_suf[i][j+1],a[i][j]);
			mn_suf[i][j]=min(mn_suf[i][j+1],a[i][j]);
		}
	}
	for(int i=1;i<m;i++){
		vector<pii>a;
		for(int j=1;j<=n;j++)a.push_back({mn_pre[j][i],j});
		sort(a.begin(),a.end(),greater<pii>());
		pre1[0]=1e9,suf1[n+1]=0;
		pre2[0]=0,suf2[n+1]=1e9;
		for(int j=1;j<=n;j++){
			int x=a[j-1].se;
			pre1[j]=min(pre1[j-1],mn_pre[x][i]);
			pre2[j]=max(pre2[j-1],mx_suf[x][i+1]);
		}
		for(int j=n;j;j--){
			int x=a[j-1].se;
			suf1[j]=max(suf1[j+1],mx_pre[x][i]);
			suf2[j]=min(suf2[j+1],mn_suf[x][i+1]);
		}
		for(int j=1;j<n;j++){
			if(pre1[j]>suf1[j+1]&&pre2[j]<suf2[j+1]){
				puts("YES");
				for(int i=1;i<=n;i++)ans[i]='B';
				for(int k=0;k<j;k++)ans[a[k].se]='R';
				for(int i=1;i<=n;i++)putchar(ans[i]);
				printf(" %d\n",i);
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}