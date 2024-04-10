#include <iostream>
#include <cstdio>
using namespace std;
int n,q,a[20005],l[20005],r[20005],k[20005];
int log_2[20005],f[20005][15][31],st[20005][15][31];
int val[20005][31],ans[20005];
int ask(int l,int r,int k){
	int w=log_2[r-l+1];
	return max(st[l][w][k],st[r-(1<<w)+1][w][k]);
}
int main(){
	cin>>n>>q;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=q;i++)scanf("%d%d%d",&l[i],&r[i],&k[i]);
	for (int i=2;i<=n;i++)log_2[i]=log_2[i/2]+1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=30;j++)
			f[i][0][j]=min(n,i+a[i]+j);
	for (int j=1;j<15;j++){
		for (int i=1;i<=n;i++)
			for (int k=0;k<=30;k++)
				st[i][0][k]=f[i][j-1][k];
		for (int w=1;(1<<w)<=n;w++)
			for (int i=1;i+(1<<w)-1<=n;i++)
				for (int k=0;k<=30;k++)
					st[i][w][k]=max(st[i][w-1][k],st[i+(1<<(w-1))][w-1][k]);
		for (int i=1;i<=n;i++)
			for (int k=0;k<=30;k++)
				for (int l=0;l<=k;l++){
					int p=f[i][j-1][l];
					f[i][j][k]=max(f[i][j][k],ask(i,p,k-l));
				}
	}
	for (int i=1;i<=q;i++)
		for (int j=0;j<=30;j++)val[i][j]=l[i];
	for (int t=14;t>=0;t--){
		for (int i=1;i<=n;i++)
			for (int j=0;j<=30;j++)
				st[i][0][j]=f[i][t][j];
		for (int w=1;(1<<w)<=n;w++)
			for (int i=1;i+(1<<w)-1<=n;i++)
				for (int j=0;j<=30;j++)
					st[i][w][j]=max(st[i][w-1][j],st[i+(1<<(w-1))][w-1][j]);
		for (int i=1;i<=q;i++){
			int fg=1;
			for (int l1=0;l1<=k[i];l1++){
				int p=val[i][l1];
				if (ask(l[i],p,k[i]-l1)>=r[i])fg=0;
			}
			if (fg==1){
				ans[i]+=(1<<t);
				for (int l1=k[i];l1>=0;l1--){
					int p=val[i][l1];
					for (int l2=0;l1+l2<=k[i];l2++)
						val[i][l1+l2]=max(val[i][l1+l2],ask(l[i],p,l2));
				}
			}
		}
	}
	for (int i=1;i<=q;i++){
		if (val[i][k[i]]<r[i])ans[i]++;
		printf("%d\n",ans[i]);
	}
	return 0;
}