#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if (b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
int main(){
	int n;
	cin>>n;

	for (int i=1;i<=n;i++){
		int b = i;
		int a = n-i;
		if (a>=b){
			continue;
		}
		if (gcd(a,b)==1){
			cout<<a<<" "<<b<<endl;
			return 0;
		}
	}
	return 0;
}