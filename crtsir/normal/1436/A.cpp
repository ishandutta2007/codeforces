#include<bits/stdc++.h>
using namespace std;
int T=1,n,a[103],m;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
			m-=a[i];
		}
		if(m)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}