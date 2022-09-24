#include <bits/stdc++.h>

using namespace std;

string B[3];

bool D[3][111];

int tk()
{

	int n,i,j,l;
	scanf("%d%d",&n,&l);
	
	for(i=0;i<3;i++) cin>>B[i];
	
	for(i=0;i<3;i++)for(j=0;j<n;j++){
		D[i][j]=0;
		if(B[i][j]=='s') B[i][j]='.',D[i][j]=1;
	}
	
	for(l=1;l<n;l++){
		if(D[0][l-1]&&B[0][l]=='.'){
			D[0][l]=1;
			if(B[1][l] == '.') D[1][l]=1;
		}
		if(D[1][l-1]&&B[1][l]=='.'){
			D[1][l]=1;
			if(B[0][l] == '.') D[0][l]=1;
			if(B[2][l] == '.') D[2][l]=1;
		}
		if(D[2][l-1]&&B[2][l]=='.'){
			D[2][l]=1;
			if(B[1][l] == '.') D[1][l]=1;
		}
		
		for(i=0;i<3;i++)for(j=0;j<n;j++){
			if(B[i][j]!='.'){
				if(j-2 >= 0) B[i][j-2] = B[i][j]; B[i][j] = '.';
			}
		}
		
		for(i=0;i<3;i++) if(B[i][l]!='.') D[i][l]=0;
	}
	
	return D[0][n-1]||D[1][n-1]||D[2][n-1];
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int _k;
	scanf("%d",&_k);
	while(_k--) printf("%s\n",tk()?"YES":"NO");
	
	return 0;
}