#include<bits/stdc++.h>
using namespace std;
#define N 100000
int deg[N+1];
int main(){
	int n,i;scanf("%d",&n);
	for(i=1;i<n;i++){
		int x,y;scanf("%d%d",&x,&y);
		deg[x]++;deg[y]++;
	}
	for(i=1;i<=n;i++)if(deg[i]==2)return printf("NO"),0;
	printf("YES");
	return 0;
}