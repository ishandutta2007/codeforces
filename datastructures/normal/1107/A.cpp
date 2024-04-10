#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int t;
signed main(){
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cin>>s;
		if (s.size()==2&&s[0]>=s[1])puts("NO");
		else{
			puts("YES");
			cout<<2<<endl<<s[0]<<' ';
			for (int i=1;i<s.size();i++)cout<<s[i];
			cout<<endl;
		}
	}
	return 0;
}