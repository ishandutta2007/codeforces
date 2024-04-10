#include<bits/stdc++.h>
using namespace std;
int n,k,a,ans;
int main(){
	cin>>n>>k;
	while(n--){
		cin>>a;
		if(k<a)ans+=2;
		else ans++;
	}cout<<ans;
}