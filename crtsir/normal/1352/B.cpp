#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		if(n%2&&k%2==0||n<k){
			cout<<"NO\n";
			continue;
		}
		if(n%2==0&&k%2!=0){
			if(k*2>n){cout<<"NO\n";continue;}
			cout<<"YES\n";
			for(int i=1;i<k;i++)
				cout<<2<<' ',n-=2;
			cout<<n<<endl;
		}
		else{
			cout<<"YES\n";
			for(int i=0;i<k-1;i++)
				cout<<1<<' ',n--;
			cout<<n<<endl;
		}
	} 
}