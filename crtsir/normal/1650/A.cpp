#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		string s;
		char c;
		cin>>s>>c;
		bool ok=0;
		for(int i=0;i<s.size();i+=2)
			if(s[i]==c)
				ok=1;
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}