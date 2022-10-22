#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int a[2];
int main(){
	cin>>t;
	while(t--){
		cin>>n;n*=2;
		a[0]=a[1]=0;
		while(n--)cin>>x,a[x&1]++;
		puts(a[0]==a[1]?"Yes":"No");
	}
}