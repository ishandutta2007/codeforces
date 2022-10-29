#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector <int > v;
main(){
	long long a,n,c,b=0,x=0,i;
	cin>>n>>c;
	x=c;
	for (i=2;i<=n;++i){
		cin>>a;
		if (c>=a*2){
			v.pb(i);
			x+=a;
		}
		else b+=a;
	}
	if (x<=b){
		cout <<0;
	}
	else {
		cout <<v.size()+1<<"\n1 ";
		for (i=0;i<v.size();++i){
			cout <<v[i]<<" ";
		}
	}
}