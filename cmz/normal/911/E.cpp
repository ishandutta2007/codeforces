#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],f[maxn],D[maxn],Dtop,top,Ans[maxn],Atop,kk[maxn];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i) scanf("%d",&a[i]),kk[i]=a[i],f[a[i]]=1;
	top=1;
	for (int i=m+1;i<=n;++i){
		while (f[top]) ++top;
		a[i]=top; ++top;
	}
	top=1;
	for (int i=1;i<=n;++i){
		D[++Dtop]=a[i];
		while (D[Dtop]==top){
			--Dtop; ++top;
		}
	}
	if (Dtop>0){
		puts("-1");
		return 0;
	}
	top=0;
	for (int i=m;i>=1;--i){
		int k=kk[i]-1;
		while (k>top){
			if (!f[k]) Ans[++Atop]=k; f[k]=1; --k;
		}
		top=kk[i];
	} //printf("top=%d\n",top);
	for (int i=n;i>=1;--i) if(!f[i]) Ans[++Atop]=i;
	for (int i=1;i<=m;++i) printf("%d ",a[i]);
	for (int i=1;i<=Atop;++i) printf("%d ",Ans[i]);
}