#include<bits/stdc++.h>
using namespace std;
int t,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		cout<<(b-a%b)%b<<"\n";
	}
}