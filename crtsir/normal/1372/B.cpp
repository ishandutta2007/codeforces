#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;
	while(T--){
		int n,a=-1,b=-1;
		cin>>n;
		for(int i=2;i<=sqrt(n);i++)
			if(n%i==0){
				a=n/i;
				b=n-n/i;
				break;
			}
		if(a==-1)a=1,b=n-1;
		cout<<a<<' '<<b<<endl;
	}
}