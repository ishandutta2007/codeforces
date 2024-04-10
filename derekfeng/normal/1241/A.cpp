#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;cin>>q;
	while (q--){
		int n;cin>>n;
		if (n==2) cout<<"2";
		else if (n==3) cout<<"1";
		else if (n%2==0) cout<<"0";
		else cout<<"1";
		puts("");
	}
}