#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;while(T--){
		int a,b;cin>>a>>b;
		cout<<pow(max(min(a,b)*2,max(a,b)),2)<<endl;
	}
}