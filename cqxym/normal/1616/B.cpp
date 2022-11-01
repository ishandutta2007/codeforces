#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
inline void Solve(){
	int n;
	cin>>n;
	string s,t,g;
	cin>>s;
	t+=s[0];
	g=t+s[0];
	for(R i=1;i!=n;i++){
		if(s[i-1]<s[i]){
			break;
		}
		t+=s[i];
	}
	s=t;
	reverse(s.begin(),s.end());
	t+=s;
	if(g<t){
		t=g;
	}
	cout<<t<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
/*
1
3
cbb
*/