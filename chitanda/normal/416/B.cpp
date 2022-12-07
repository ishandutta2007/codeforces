#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int S[50010][7],m,n;
int T;

int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&T);
			S[i][j]=max(S[i][j-1],S[i-1][j])+T;
		}
		printf("%d ",S[i][n]);
	}
	return 0;
}