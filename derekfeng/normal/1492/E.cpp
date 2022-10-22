#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> >a;
int maxn,p,pp[5],cnt,b[250004]; 
void check(){
	for(int i=2;i<=n;i++){
		int cur=0;
		for(int j=1;j<=m;j++)if(b[j]!=a[i][j])cur++;
		if(cur>3)return;
		if(cur<3)continue;
		bool ok=1;
		for(int j=1;j<=m;j++)
			if(b[j]<0){
				b[j]=a[i][j],ok=0;
				break;
			}
		if(ok)return;
	}
	puts("Yes");
	for(int i=1;i<=m;i++)printf("%d ",b[i]);
	exit(0);
}
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n+1);
	for(int i=1;i<=n;i++)a[i].resize(m+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=2;i<=n;i++){
		int cur=0;
		for(int j=1;j<=m;j++)if(a[i][j]!=a[1][j])cur++;
		if(maxn<cur)maxn=cur,p=i;
	}
	if(maxn<3){puts("Yes");for(int i=1;i<=m;i++)printf("%d ",a[1][i]);return 0;}
	if(maxn>4){puts("No");return 0;}
	for(int i=1;i<=m;i++)if(a[p][i]!=a[1][i])pp[++cnt]=i;
	for(int i=1;i<=cnt;i++)for(int j=1;j<=cnt;j++){
		for(int k=1;k<=m;k++)b[k]=a[1][k];
		b[pp[i]]=a[p][pp[i]],b[pp[j]]=-1;
		check();
	}
	puts("No");
}