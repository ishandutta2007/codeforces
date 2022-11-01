#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
#define L long long
int A[201],B[201],C[201];
L f[201][201][201];
inline void Max(L&a,L b){
	a=a>b?a:b;
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	for(R i=1;i<=a;i++){
		cin>>A[i];
	}
	for(R i=1;i<=b;i++){
		cin>>B[i];
	}
	for(R i=1;i<=c;i++){
		cin>>C[i];
	}
	sort(A+1,A+1+a);
	sort(B+1,B+b+1);
	sort(C+1,C+c+1);
	for(R i=0;i<=a;i++){
		for(R j=0;j<=b;j++){
			for(R k=0;k<=c;k++){
				if(i!=0&&j!=0){
					Max(f[i][j][k],f[i-1][j-1][k]+A[i]*B[j]);
				}
				if(i!=0&&k!=0){
					Max(f[i][j][k],f[i-1][j][k-1]+A[i]*C[k]);
				}
				if(j!=0&&k!=0){
					Max(f[i][j][k],f[i][j-1][k-1]+B[j]*C[k]);
				}
			}
		}
	}
	printf("%lld",f[a][b][c]);
	return 0;
}