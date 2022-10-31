#include<bits/stdc++.h>
const int N=1000005; 
using namespace std;

string s;
int t,n;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>s;
		for(int i=0;i<n;i++)
			if(s[i]=='U')cout<<'D';
			else if(s[i]=='D') cout<<'U';
			else cout<<s[i];
		cout<<endl; 
	}
}