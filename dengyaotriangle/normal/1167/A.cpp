#include<bits/stdc++.h>

using namespace std;

char s[104];

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>(s+1);
		bool ok=0;
		for(int i=1;i<=n-10;i++){
			if(s[i]=='8')ok=1;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	return 0;
}