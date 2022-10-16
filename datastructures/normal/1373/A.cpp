#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int t,a,b,c;
signed main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if (a>=c)cout<<-1<<' ';
		else cout<<1<<' ';
		if (a*b<=c)cout<<-1<<endl;
		else cout<<b<<endl;
	}
	return 0;
}