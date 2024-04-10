#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxm 30
using namespace std;

int T,a[maxm+5],b[maxm+5],i,j,k;

int check(int x,int y){
	if (x>y) return 0; if (x==y) return 1;
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	for(i=0;i<maxm;i++) a[i]=x>>i&1,b[i]=y>>i&1;
	int m;
	for(i=0;i<maxm;i++) if (a[i]!=b[i]) m=i;
	j=0; while (a[j]) j++;
	for(i=0;i<=m;i++) if (a[i]!=b[i]){
		if (a[i]<b[i]) return 0;
		while (j<=i||a[j]) j++;
		if (j==m) return 1;
		a[j]++;
	}
	return 0;
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&j,&k);
		if (check(j,k)) printf("YES\n");
		else printf("NO\n");
	}
}