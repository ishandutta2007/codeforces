#include <iostream>
#include <cstdio>
using namespace std;
#define MAXN 110
int n,f[2][4],map[MAXN][MAXN];
char buf[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=0;i<4;++i){
		for(int j=1;j<=n;++j){
			scanf("%s",buf);
			for(int k=1;k<=n;++k)
				f[0][i]+=((j&1)^(k&1))^(buf[k-1]=='0'),
				f[1][i]+=((j&1)^(k&1))^(buf[k-1]=='1');
		}
	}
	printf("%d\n",
		min(f[0][0]+f[0][1]+f[1][2]+f[1][3],
		min(f[0][0]+f[1][1]+f[0][2]+f[1][3],
		min(f[1][0]+f[0][1]+f[0][2]+f[1][3],
		min(f[0][0]+f[1][1]+f[1][2]+f[0][3],
		min(f[1][0]+f[0][1]+f[1][2]+f[0][3],
		min(f[1][0]+f[1][1]+f[0][2]+f[0][3],
			0x7fffffff)))))));
	return 0;
}