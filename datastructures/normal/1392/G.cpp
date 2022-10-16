#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k,a[1000005],b[1000005],f[1100005],g[1100005],num1,num2,ans,id;
int vs[1000005],vt[1000005],sta[1000005][25],stat[1000005][21];
char s[25],t[25];
inline int bc(int x){
	if (x==0)return 0;
	return bc(x-(x&(-x)))+1;
}
int main(){
	cin>>n>>m>>k;
	scanf("%s%s",s+1,t+1);
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	for (int i=1;i<=k;i++)sta[n+1][i]=i;
	for (int i=n;i>=1;i--){
		for (int j=1;j<=k;j++)sta[i][j]=sta[i+1][j];
		for (int j=1;j<=k;j++){
			if (sta[i][j]==a[i])sta[i][j]=b[i];
			else if (sta[i][j]==b[i])sta[i][j]=a[i];
		}
	}
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=k;j++){
			vs[i]*=2,vt[i]*=2;
			if (s[sta[i][j]]=='1')vs[i]++;
			if (t[sta[i][j]]=='1')vt[i]++;
		}
	}
	memset(f,-1,sizeof(f));
	memset(g,-1,sizeof(g));
	for (int i=1;i<=n+1;i++){
		if (f[vs[i]]==-1)f[vs[i]]=i;
		g[vt[i]]=i;
	}
	for (int i=(1<<k)-1;i>=0;i--){
		if (f[i]!=-1){
			for (register int j=0;j<k;j++){
				if (i&(1<<j)){
					if (f[i^(1<<j)]==-1)f[i^(1<<j)]=f[i];
					else f[i^(1<<j)]=min(f[i^(1<<j)],f[i]);
				}
			}
		}
		if (g[i]!=-1){
			for (register int j=0;j<k;j++){
				if (i&(1<<j)){
					if (g[i^(1<<j)]==-1)g[i^(1<<j)]=g[i];
					else g[i^(1<<j)]=max(g[i^(1<<j)],g[i]);
				}
			}
		}
	}
	for (register int i=1;i<=k;i++){
		if (s[i]=='1')num1++;
		if (t[i]=='1')num2++;
	}
	for (register int i=0;i<(1<<k);i++){
		if (f[i]!=-1&&g[i]!=-1&&g[i]-f[i]>=m){
			int cnt=bc(i);
			if (k-(num1-cnt)-(num2-cnt)>ans)ans=k-(num1-cnt)-(num2-cnt),id=i;
		}
	}
	cout<<ans<<endl<<f[id]<<' '<<g[id]-1<<endl;
	return 0;
}