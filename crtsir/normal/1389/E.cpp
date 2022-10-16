#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		long long m,d,w;
		cin>>m>>d>>w;
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		long long x=w/__gcd(w,d-1);
		long long tmp1=min(m,d),tmp2=(tmp1-1)/x;
		cout<<tmp1*tmp2-((tmp2)*(tmp2+1)/2)*x<<endl;
	}
}