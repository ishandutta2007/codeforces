#include<bits/stdc++.h>
using namespace std;
int T,n; 
int main(){cin>>T;
	while(T--){
		cin>>n;if(n%4){cout<<"NO\n";continue;}
		cout<<"YES\n";
		for(int i=0;i<n/2;i++)cout<<(i+1)*2<<' ';
		for(int i=0;i<n/4;i++)cout<<i*2+1<<' ';
		for(int i=n/4;i<n/2;i++)cout<<i*2+3<<' ';cout<<endl;
	}
}