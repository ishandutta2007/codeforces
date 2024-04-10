#include <cstdio>
#include <vector>

using namespace std;

vector <int> K;

int D[505][505],A[505];

int main()
{
	int n,i,j,k,c;
	scanf("%d",&n);
	
	for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&D[i][j]);
	
	for(k=1;k<=n;k++){
		c=0;
		for(i=0;i<n;i++){
			if(D[i][0] >= 0){
				for(j=0;j<n;j++){
					if(D[i][j] != 0 && D[i][j] != k) break;
				}
				if(j==n){
					c=i;
					break;
				}
			}
		}
		A[c] = k;
		D[c][0] = -1;
			
		for(i=0;i<n;i++) for(j=0;j<n;j++) if(D[i][j]==k) D[i][j]=0;
		
	}
	
	
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	
	return 0;
}