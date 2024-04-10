#include <cstdio>

using namespace std;

bool D[505][505];

int n,k,i,j,l,a,c;

int main()
{
	scanf("%d %d",&n,&k);
	D[0][0]=1;
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		for(j=k;j>=0;j--){
			for(l=k;l>=0;l--){
				if(D[j][l]){
					if(l+a <= k) D[j][l+a]=1, D[j+a][l+a]=1;
				}
			}
		}
	}
	
	for(i=0;i<=k;i++) if(D[i][k]) c++;
	printf("%d\n",c);
	
	for(i=0;i<=k;i++) if(D[i][k]) printf("%d ",i);
	printf("\n");
	
	return 0;
}