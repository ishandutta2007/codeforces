#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+10;
int n,m,k;
int a[maxn][maxn],l[maxn],r[maxn],tot[maxn],alive[maxn],pre[maxn][maxn],last[maxn][maxn];
int Val[maxn][maxn],f[maxn][maxn],ans[maxn],cur[maxn];
char s[maxn];
int main(){
	//freopen(".in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;++i){
		scanf("%s",s+1);
		for (int j=1;j<=m;++j)
			if (s[j]=='1') Val[i][j]=1; else Val[i][j]=0;
	}
	
	for (int i=1,lst,now;i<=n;++i){
		lst=0; now=0;
		for (int j=1;j<=m;++j){
			++now;
			if (Val[i][j]==1){
				if (!lst){
					lst=j; now=0; continue;
				}
				a[i][++tot[i]]=now; now=0; 
			}
		}
		if (lst!=0) alive[i]=1;
		/*puts("--------------------");
		for (int j=kkk+1;j<=tot;++j) printf("a[%d]=%d\n",j,a[j]);
		puts("--------------------");*/
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=tot[i];++j) pre[i][j]=pre[i][j-1]+a[i][j];
		for (int j=tot[i];j>=1;--j) last[i][j]=last[i][j+1]+a[i][j];
		for (int j=1;j<=tot[i];++j) cur[tot[i]-j+1]=last[i][j];
		for (int j=1;j<=tot[i];++j) last[i][j]=cur[j];
	}
	int Ans=0; 
	for (int i=1,L,R;i<=n;++i){
		L=0; R=0;
		for (int j=1;j<=m;++j) if (Val[i][j]==1){
			L=j; break;
		}
		for (int j=m;j>=1;--j) if (Val[i][j]==1){
			R=j; break;
		}
		if (L==0&&R==0) continue;
		Ans+=(R-L)+1;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=min(k,tot[i]);++j){
			for (int l=0;l<=j;++l){
				f[i][j]=max(f[i][j],pre[i][l]+last[i][j-l]);
			}
			//printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
		f[i][tot[i]+1]=f[i][tot[i]]+1; ++tot[i];
	}
	for (int i=1;i<=n;++i){
		for (int j=k;j>=0;--j)
			for (int l=0;l<=min(min(k,tot[i]),j);++l) ans[j]=max(ans[j],ans[j-l]+f[i][l]);
	}
	int kk=0;
	for (int i=0;i<=k;++i){
		kk=max(kk,ans[i]);
		//printf("ans[%d]=%d\n",i,ans[i]);
	}
	if (Ans-kk<0) puts("0"); else printf("%d\n",Ans-kk);
	return 0;
}