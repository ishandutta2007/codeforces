#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

int n,a,b;

bool chk(){
	cin>>n>>a>>b;
	if(a==1)return n%b==1%b;
	for(int i=1;i<=n;i*=a)if(i%b==n%b)return 1;
	return 0;
} 

void solve(){
	cout<<(chk()?"Yes":"No")<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
}