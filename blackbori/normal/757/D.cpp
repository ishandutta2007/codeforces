#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int D[99][99];
int P[77][1<<20], Mod=1e9+7;
int n,ans;
string s;

int main()
{
	int i,j,k,l;

	scanf("%d",&n);

	cin>>s;

	for(l=1;l<=20;l++){
		for(i=0;i<n;i++){
			for(j=i,k=0;j<n && k<l;j++){
				k = k*2 + (s[j]=='1');
			}
			if(k==l) D[i][l] = j-i;
		}
	}
/*
	for(i=0;i<n;i++){
		for(l=1;l<=20;l++) printf("%d ",D[i][l]);
		printf("\n");
	}
*/
	P[n][0] = 1;
	for(i=n-1;i>=0;i--){
		P[i][0] = 1;
		for(l=1;l<=20;l++) if(D[i][l]){
			for(j=0;j<1<<20;j++) P[i][j|(1<<(l-1))] = (P[i][j|(1<<(l-1))]+P[i+D[i][l]][j])%Mod;
		}
		for(l=1;l<=20;l++) ans = (ans+P[i][(1<<l)-1]) % Mod;
//		printf("%d\n",ans);
	}

	printf("%d\n",ans);

	return 0;
}