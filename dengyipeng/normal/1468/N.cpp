#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int T,a1,a2,a3,c1,c2,c3,a4,a5;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&c1,&c2,&c3);
		scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
		c1-=a1,c2-=a2,c3-=a3;
		if (c1<0||c2<0||c3<0) printf("NO\n"); else {
			a4-=min(c1,a4);
			c3-=a4;
			a5-=min(c2,a5);
			c3-=a5;
			if (c3<0) printf("NO\n"); 
			else printf("YES\n");
		}
	}
}