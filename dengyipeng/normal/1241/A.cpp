#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int q,n,i,j,k;

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d",&q);
	while (q--){
		scanf("%d",&n);
		if (n==2) printf("2\n"); else {
			if (n&1) printf("1\n");
				else printf("0\n");
		}
	}
}