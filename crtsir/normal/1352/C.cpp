#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		if(k%(n-1)==0)
			cout<<k/(n-1)*n-1<<endl;
		else
			cout<<(k/(n-1))*n+k%(n-1)<<endl;
	} 
}