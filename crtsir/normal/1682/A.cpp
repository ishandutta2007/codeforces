#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,n;
	cin>>T;
	string s;
	while(T--){
		cin>>n>>s;int cnt=0;
		for(int i=n/2;i<s.size();i++)
			if(s[i]==s[n/2])
				cnt++;
			else
				break;
		for(int i=n/2-1;i>=0;i--)
			if(s[i]==s[n/2])
				cnt++;
			else
				break;
		cout<<cnt<<endl;
	}
}