#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n , k;
		cin>>n>>k;
		int a = k / (n - 1) , tt = k % (n - 1);
		a *= n;
		cout<<(tt == 0 ? a - 1 : a+tt)<<endl;
	}
}