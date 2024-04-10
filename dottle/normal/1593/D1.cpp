#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

void solve(){
	int ans=0,n;
	cin>>n;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		ans=gcd(ans,a[i]-a[i+1]);
	if(ans!=0)
		cout<<abs(ans)<<endl;
	else cout<<-1<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}