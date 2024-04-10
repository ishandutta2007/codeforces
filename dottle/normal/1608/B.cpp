#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

void solve(){
	int n,a,b;cin>>n>>a>>b;
	if(abs(a-b)>1||a+b>n-2){
		cout<<-1<<endl;
		return ;
	}
	if(a==b){
		for(int i=1;i<=a;i++)
			cout<<i<<' '<<n-i+1<<" ";
		for(int i=a+1;i<=n-a;i++)
			cout<<i<<' ';
		cout<<endl;
	}else if(a>=b){
		for(int i=1;i<=a;i++)
			cout<<i<<' '<<n-i+1<<" ";
		for(int i=n-a;i>a;i--)
			cout<<i<<' ';
		cout<<endl;
	}else{
		for(int i=1;i<=b;i++)
			cout<<n-i+1<<' '<<i<<" ";
		for(int i=n-b;i>b;i--)
			cout<<n-i+1<<' ';
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}