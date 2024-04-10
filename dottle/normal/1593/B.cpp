#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

string s;
void solve(){
	cin>>s;
	int ans=1e7,p0=0,p5=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')p0=i;
		if(s[i]=='5')p5=i;
	}
	for(int i=p0-1;i>=0;i--)
		if(s[i]=='5'||s[i]=='0'){
			ans=s.size()-i-2;
			break;
		}
	for(int i=p5-1;i>=0;i--)
		if(s[i]=='2'||s[i]=='7'){
			ans=min(ans,(int)(s.size()-i-2));
			break;
		}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}