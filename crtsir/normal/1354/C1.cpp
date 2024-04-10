#include<bits/stdc++.h>
using namespace std;
long double p=57.295779513082320876798154814105;
int main(){
	int T;cin>>T;while(T--){
		int n;cin>>n;n*=2;
		cout<<fixed<<setprecision(10)<<tan(((n*90.0-180)/n)/p)<<endl;
	}
}