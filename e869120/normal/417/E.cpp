#include<iostream>
using namespace std;
int n,m,a[1000],b[1000];
int main(){
	cin>>n>>m;
	if(n%2==0){for(int i=0;i<n-1;i++)a[i]=1;a[n-1]=(n-2)/2;}
	if(n%2==1){for(int i=0;i<n-2;i++)a[i]=1;a[n-2]=2;a[n-1]=(n+1)/2;}
	if(n==1){a[0]=1;}
	if(n==2){a[0]=3;a[1]=4;}
	if(m%2==0){for(int i=0;i<m-1;i++)b[i]=1;b[m-1]=(m-2)/2;}
	if(m%2==1){for(int i=0;i<m-2;i++)b[i]=1;b[m-2]=2;b[m-1]=(m+1)/2;}
	if(m==1){b[0]=1;}
	if(m==2){b[0]=3;b[1]=4;}
	for(int i=0;i<n;i++){for(int j=0;j<m;j++){if(j)cout<<' ';cout<<a[i]*b[j];}cout<<endl;}
	return 0;
}