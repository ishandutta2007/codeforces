#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

int t,a,b,c,m;

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>m;
		int x=2*max(a,max(b,c))-a-b-c-1,y=a+b+c-3;
		if(m>=x&&m<=y)cout<<"yes"<<endl;
		else cout<<"No"<<endl;
	} 
}