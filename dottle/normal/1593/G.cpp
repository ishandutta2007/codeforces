#include<bits/stdc++.h>
//#define int long long
const int N=100500;
using namespace std;

void solve(){
	string s;
	vector<int> a[2];
	cin>>s;
	a[0].resize(s.size()+5);
	a[1].resize(s.size()+5);
	for(int i=0;i<s.size();i++){
		a[0][i+1]=a[0][i],a[1][i+1]=a[1][i];
		if(s[i]=='['||s[i]==']')
			a[i&1][i+1]++; 
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		cout<<abs(a[0][r]-a[0][l-1]-a[1][r]+a[1][l-1])<<endl;
	} 
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}