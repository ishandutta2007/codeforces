#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;
int n,a,b; 

void solve(){
	cin>>n>>a>>b;
	cout<<max(0,max(a,b)+1-n)<<' '<<max(0,max(n,b)+1-a)<<' '<<max(0,max(a,n)+1-b)<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}