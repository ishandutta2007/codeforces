#include <iostream>
using namespace std;
int N,a[3010][3],d[3010][2],i,j,n;
int main(){
	cin >> N;
	for(;j<3;j++)for(i=0;i<N;i++)cin >> a[i][j];
	d[0][0]=-1e6;
	for(n=0;n<N;n++)d[n+1][0]=max(d[n][0]+a[n][1],d[n][1]+a[n][0]),d[n+1][1]=max(d[n][0]+a[n][2], d[n][1]+a[n][1]);
	cout << d[N][0];
}