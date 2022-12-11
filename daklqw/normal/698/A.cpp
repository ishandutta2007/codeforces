#include <iostream>
#include <cstdio>
using namespace std;
/*
ai0gymcontest;
ai1gymcontest;
ai2gymcontest;
ai3gymcontest
*/
#define INF 0x7FFFFFFF
int t,n,f[2][3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&t);
		f[i&1][0]=min(f[i&1^1][0],min(f[i&1^1][1],f[i&1^1][2]))+1;
		switch(t){
			case 0:
				f[i&1][2]=f[i&1][1]=INF;
				break;
			case 1:
				f[i&1][2]=min(f[i&1^1][1],f[i&1^1][0]);
				f[i&1][1]=INF;
				break;
			case 2:
				f[i&1][1]=min(f[i&1^1][2],f[i&1^1][0]);
				f[i&1][2]=INF;
				break;
			case 3:
				f[i&1][2]=min(f[i&1^1][1],f[i&1^1][0]);
				f[i&1][1]=min(f[i&1^1][2],f[i&1^1][0]);
				break;
		}
	}
	printf("%d\n",min(f[n&1][0],min(f[n&1][1],f[n&1][2])));
	return 0;
}