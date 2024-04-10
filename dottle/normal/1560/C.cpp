#include<bits/stdc++.h>
#define int long long
//const int N=
using namespace std;

int t,a;

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>a;
		int b=sqrt(a-1);
		int p=a-b*b;
		if(p<=b)cout<<p<<' '<<b+1<<endl;
		else cout<<b+1<<' '<<b*2+2-p<<endl;
	}
}