#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string B[555];

int D1[555][555],D2[555][555],n,m,q;

int main()
{	
	int i,j,a,b,c,d;
	scanf("%d %d\n",&n,&m);
	
	for(i=0;i<n;i++) cin>>B[i];
	
	for(i=1;i<=n;i++){
		for(j=2;j<=m;j++){
			D1[i][j] = D1[i-1][j] + D1[i][j-1] - D1[i-1][j-1] + (B[i-1][j-1] == '.' && B[i-1][j-2] == '.');
		}
	}
	for(i=2;i<=n;i++){
		for(j=1;j<=m;j++){
			D2[i][j] = D2[i-1][j] + D2[i][j-1] - D2[i-1][j-1] + (B[i-1][j-1] == '.' && B[i-2][j-1] == '.');
		}
	}
	
	scanf("%d",&q);

 	while(q--){
 		scanf("%d %d %d %d",&a,&b,&c,&d);
 		printf("%d\n",(D1[c][d]-D1[c][b]-D1[a-1][d]+D1[a-1][b])+(D2[c][d]-D2[c][b-1]-D2[a][d]+D2[a][b-1]));
 	}

	return 0;
}