#include<bits/stdc++.h>
using namespace std;
int T=1,n,a[103];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int cnt=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			cnt+=a[i];
		}
		if(cnt%n)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	} 
}