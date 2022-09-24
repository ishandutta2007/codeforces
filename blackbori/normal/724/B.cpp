#include <cstdio>
#include <iostream>

using namespace std;

int n,m,D[22][22],K[22];

bool F()
{
	int i,j,c;
	
	for(i=0;i<n;i++){
		for(c=0,j=0;j<m;j++){
			if(K[j] != D[i][j]) c++;
		}
		if(c>2) return 0;
	}	
	
	return 1;
}

int main()
{
	scanf("%d %d",&n,&m);
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			K[j] = j+1;
			scanf("%d",&D[i][j]);
		}
	}
	
	if(F()){
		printf("YES");
		return 0;
	}
			
	for(i=0;i<m;i++){
		for(j=i+1;j<m;j++){
			K[i]=j+1, K[j]=i+1;
			
			if(F()){
				printf("YES");
				return 0;
			}
			K[i]=i+1, K[j]=j+1;
		}
	}
	
	printf("NO");
	
	return 0;
}