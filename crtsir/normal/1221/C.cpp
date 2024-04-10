#include<bits/stdc++.h>
using namespace std;
int main(){
	long long t;cin>>t;
	while(t--){
		long long a,b,c;cin>>a>>b>>c;
		cout<<min(min(a,b),(a+b+c)/3)<<endl;
	}
}