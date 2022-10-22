#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;cin>>T;
	while(T--){
		long long a,b;cin>>a>>b;
		if(b==1)puts("NO");
		else if(b==2){
			puts("YES");
			cout<<a<<" "<<3*a<<" "<<4*a<<"\n";
		}else{
			puts("YES");
			cout<<a<<" "<<(b-1)*a<<" "<<a*b<<"\n"; 
		}
	}
}