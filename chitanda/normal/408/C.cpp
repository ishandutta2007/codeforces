#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

int a,b;

int main(){
	scanf("%d%d",&a,&b);
	if (a>b) swap(a,b);
	for(int i=2;i<a;i++)
		for(int j=2;j<a;j++)
			if (i*i+j*j==a*a){
				for(int k=2;k<b;k++)
					for(int l=2;l<b;l++)
						if (k*k+l*l==b*b){
							if (j==l) continue;
							if (i*k==j*l){
								printf("YES\n");
								printf("0 0\n");
								printf("%d %d\n",-i,j);
								printf("%d %d\n",k,l);
								return 0;
							}
						}
			}
	printf("NO\n");
	return 0;
}