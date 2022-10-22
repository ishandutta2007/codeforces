#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,t;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		if(b>=a){
			cout<<b;puts("");
			continue;
		}
		a-=b;
		if(c<=d){
			puts("-1");
		}else{
			cout<<b+(a+c-d-1)/(c-d)*c;puts("");
		}
	}
}