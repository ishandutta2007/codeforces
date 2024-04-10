#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		cout<<min(min(min(a+b,b+c),c+a),(a+b+c)/2)<<endl;
	}
}