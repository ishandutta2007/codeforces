#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long LL; 
int main(){
	int n,cnt=0,e;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>e;
		cnt+=e;
	}
	if(n==1){
		if(cnt==1){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}else{
		if(cnt==n-1){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
	}
	return 0;
}