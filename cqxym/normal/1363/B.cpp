#include<iostream>
using namespace std;
#define R register int
int ct[1001];
inline void Solve(){
	string s;
	cin>>s;
	int len=s.length();
	for(R i=1;i<=len;i++){
		ct[i]=ct[i-1]+s[i-1]-'0';
	}
	int ans=1e6;
	for(R i=0;i<=len;i++){
		int x=i-ct[i]+ct[len]-ct[i],y=ct[i]+len-i-ct[len]+ct[i];
		x=x<y?x:y;
		ans=ans<x?ans:x;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}