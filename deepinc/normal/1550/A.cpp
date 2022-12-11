#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t; while(t--){
		int q;cin>>q;
		int s=sqrt(q);
		cout<<s+(s*s!=q)<<endl;
	}
}