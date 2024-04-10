#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			int a,b,N;
			cin>>a>>b>>N;
			if(N%3==0)cout<<a<<'\n';
			if(N%3==1)cout<<b<<'\n';
			if(N%3==2)cout<<(a^b)<<'\n';
		}
		return 0;
}