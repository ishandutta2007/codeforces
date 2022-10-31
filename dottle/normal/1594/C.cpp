#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

string s;
int n;char c;

void solve(){
	cin>>n>>c>>s;
	int fl=0;
	for(auto x:s)fl+=x==c;
	if(fl==n){
		cout<<0<<endl;return;
	} 
	for(int i=s.size()/2;i<s.size();i++){
		if(s[i]==c){cout<<"1\n"<<i+1<<endl;return;}
	}
	cout<<"2\n"<<n<<' '<<n-1<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}