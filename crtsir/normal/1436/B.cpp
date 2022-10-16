#include<bits/stdc++.h>
using namespace std;
int T=1,n,ans[103][103];
bool isprime(int x){
	if(x==1)return 1;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n-1;i++)
			for(int j=0;j<n-1;j++)
				ans[i][j]=1;
		int x=0;
		for(int i=1;i<=100000;i++) 
			if(!isprime(i)&&isprime(i+n-1)){
				x=i;
				break;
			}
		for(int i=0;i<n-1;i++){
			ans[n-1][i]=x;
			ans[i][n-1]=x;
		}
		for(int i=1;i<=100000;i++)
			if(!isprime(i)&&isprime(i+(n-1)*x)){
				ans[n-1][n-1]=i;
				break;
			}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<ans[i][j]<<' ';
			cout<<endl;
		}
	}
}