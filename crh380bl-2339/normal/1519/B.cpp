#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,T,i,j,k;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		if(k+1==n*m)puts("YES");
		else puts("NO");
	}
	return 0;
}