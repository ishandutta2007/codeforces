#include<bits/stdc++.h>
using namespace std;int T;
int main(){cin>>T;
	while(T--){
		string s;cin>>s;
		for(int i=0;i<s.size();i+=2)cout<<s[i];cout<<s[s.size()-1]<<endl;
	}
}