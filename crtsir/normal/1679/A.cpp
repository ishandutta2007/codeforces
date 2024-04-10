#include<bits/stdc++.h>
using namespace std;
int T=1;
int main(){
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		if(n<4||n&1)
			cout<<-1<<endl;
		else
			cout<<((n+5)/6)<<' '<<(n/4)<<endl;
	}
}