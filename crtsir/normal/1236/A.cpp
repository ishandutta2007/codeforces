#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		int a,b,c,ans;
		cin>>a>>b>>c;
		ans=min(b,c/2)*3;
		b-=min(b,c/2);
		cout<<ans+min(a,b/2)*3<<endl;
	}
}