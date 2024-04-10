#include<bits/stdc++.h>

using namespace std;


long long ans=0;
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n-1;i++){
		long long cur=4;
		if(i!=1) cur*=3;
		if(i!=n-1) cur*=3;
		for(int j=1;j<=n+n-2;j++){
			if((j<i-1)||(j>=i+n+1)) cur*=4;
		}
		ans+=cur;
	}
	cout<<ans;
	return 0;
}