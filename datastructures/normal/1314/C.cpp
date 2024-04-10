#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define int long long
#define inf 4000000000000000000
using namespace std;
int n,m,k;
char s[1005];
int lcp[1005][1005];
int f[1005][1005];
struct node{
	int l,r;
}c[6000005];
int tot;
bool cmp(node a,node b){
	int mlen=min(a.r-a.l+1,b.r-b.l+1);
	if (lcp[a.l][b.l]>=mlen)return a.r-a.l+1<b.r-b.l+1;
	return s[a.l+lcp[a.l][b.l]]<s[b.l+lcp[a.l][b.l]];
}
int check(int id){
	int l=c[id].l,r=c[id].r;
	memset(f,0,sizeof(f));
	f[0][0]=1;
	f[1][0]=-1;
	for (int j=0;j<=m;j++)
		for (int i=0;i<=n;i++){
			if (i>0)f[i][j]+=f[i-1][j];
			if (f[i][j]>inf)f[i][j]=inf;
			if (i==n||j==m)continue;
			if (f[i][j]==0)continue;
			int p=-1;
			if (lcp[i+1][l]>=r-l+1)p=i+(r-l+1);
			else{
				if (i+1+lcp[i+1][l]<=n&&(l+lcp[i+1][l]>r||s[i+1+lcp[i+1][l]]>s[l+lcp[i+1][l]]))p=i+1+lcp[i+1][l];
				else p=-1;
			}
			if (p!=-1){
				f[p][j+1]+=f[i][j];
				if (f[p][j+1]>inf)f[p][j+1]=inf;
			}
		}
	return f[n][m];
}
signed main(){
	cin>>n>>m>>k;
	scanf("%s",s+1);
	for (int i=n;i>=1;i--)
		for (int j=n;j>=1;j--)
			if (s[i]==s[j])lcp[i][j]=lcp[i+1][j+1]+1;
			else lcp[i][j]=0;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++){
			if ((i-1)+(n-j)+1<m)continue;
			++tot;
			c[tot].l=i,c[tot].r=j;
		}
	sort(c+1,c+1+tot,cmp);
	int l=1,r=tot,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid)>=k)ans=mid,l=mid+1;
		else r=mid-1;
	}
	for (int i=c[ans].l;i<=c[ans].r;i++)putchar(s[i]);
	puts("");
	return 0;
}