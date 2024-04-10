#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i*2<=n;i++)
		for(int j=1;j<=m;j++)printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
	int midn=n/2+1,midm=m/2+1;
	if(n&1){
		for(int j=1;j*2<=m;j++)printf("%d %d\n%d %d\n",midn,j,midn,m-j+1);
		if(m&1)printf("%d %d\n",midn,midm);
	}
	return 0;
}