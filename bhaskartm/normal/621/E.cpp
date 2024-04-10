#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
#define f first
#define s second
 
const int N=1000000007;
int cnt[100];
const int M=100;
int mat[M][M];
int Y[M][M];
void multiply(int a[M][M],int b[M][M])
{
	memset(Y,0,sizeof Y);
	for(int i=0;i<M;i++)
	for(int j=0;j<M;j++)
	for(int k=0;k<M;k++)
	Y[i][j]=(Y[i][j]+a[i][k]*b[k][j])%N;
	memcpy(a,Y,sizeof Y);		
}
 
void power(int  a[M][M],int n)
{
	int r[M][M];
	memset(r,0,sizeof r);
	for(int i=0;i<M;i++)
	r[i][i]=1;
	while(n)
	{
		if(n&1ll)
			multiply(r,a);
		multiply(a,a);
		n>>=1;
	}
	memcpy(a,r,sizeof r);	
}
 
 
main() {
	int n, b, k, x;
	cin>>n>>b>>k>>x;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		cnt[(arr[i])%x]++;
	}
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			mat[i][(10*i+j)%x]+=cnt[j];
		}
	}
	
	
	power(mat, b);
	cout<<mat[0][k]<<endl;
	
	
	return 0;
}