#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
int n,m,r,c;
double a[N][N];
double x[N];
void gauss(){
	int i,j,k;
	for(i=1;i<m;i++){
		double mul=a[i+1][i]/a[i][i];
		for(j=i;j<=i+1;j++)
			a[i+1][j]-=a[i][j]*mul;
		a[i+1][m+1]-=a[i][m+1]*mul;
	}
	for(i=m;i;i--){
		x[i]=a[i][m+1]/a[i][i];
		a[i-1][m+1]-=a[i-1][i]*x[i];
		a[i-1][i]=0;
	}
}
int main(){
	int i,j;
	cin>>n>>m>>r>>c;
	for(i=n-1;i;i--){
		for(j=1;j<=m;j++){
			if(m==1){
				a[j][j]=1./2;
				a[j][m+1]=1+1./2*x[j];
			}
			else if(j==1){
				a[j][j]=2./3;
				a[j][j+1]=-1./3;
				a[j][m+1]=1+1./3*x[j];
			}
			else if(j==m){
				a[j][j]=2./3;
				a[j][j-1]=-1./3;
				a[j][m+1]=1+1./3*x[j];
			}
			else {
				a[j][j]=3./4;
				a[j][j-1]=a[j][j+1]=-1./4;
				a[j][m+1]=1+1./4*x[j];
			}	
		}
		gauss();
		if(i==r){
			printf("%.10lf",x[c]);
			return 0;
		}
	}
	cout<<"0";
	return 0;
}