#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n,m; scanf("%d%d",&n,&m);
		printf("%d\n",int(n>1)+int(m>1));
	}
	return 0;
}