#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int T,x,y;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&x,&y);
		if (2*x<=y) printf("%d %d\n",x,2*x);
		else printf("-1 -1\n");
	}
}