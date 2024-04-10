#include<bits/stdc++.h>
using namespace std;
int n,m,a[510][510],tmp,tt;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)scanf("%d",&tmp),a[i][j]^=tmp;
	for(int i=1;i<=n;++i,tt=0){
		for(int j=1;j<=m;++j)tt+=a[i][j],a[i+1][j]^=a[i][j],a[i][j]=0;
		if(tt&1)return puts("No"),0;
		if(i==n&&tt)return puts("No"),0;
	}
	return puts("Yes"),0;
}