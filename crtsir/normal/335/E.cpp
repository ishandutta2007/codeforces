#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	cin>>s;
	if(s=="Bob"){string s;cin>>s;cout<<s;return 0;}
	int n,h;
	cin>>n>>h;
	double ans=n,_h=0.5,_c=0.5;
	for(int i=1;i<=h;i++){
		double _n=0.5;
		for(int j=0;j<n;j++)
			ans+=(n-1-j)*_h*(1-j*_h/_c)*_n,
			_n*=(1-_h);
		_h/=2;
		_c+=_h;
	}printf("%.9lf",ans);
}