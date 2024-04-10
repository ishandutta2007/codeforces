#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
string s;
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>s;n=s.length();s=" "+s;
		int f=0;
		for(i=1;i<=n;i++) if(s[i]=='0') f=1;
		if(!f){
			cout<<"cyan"<<endl;
			continue;
		}
		f=0;
		for(i=1;i<=n;i++) if((s[i]-'0')%2==0) f++;
		if(f<2){
			cout<<"cyan"<<endl;
			continue;
		}
		int cnt=0;
		for(i=1;i<=n;i++) cnt+=s[i]-'0';
		if(cnt%3){
			cout<<"cyan"<<endl;
			continue;
		}
		else cout<<"red"<<endl;
	} 
	return 0;
}