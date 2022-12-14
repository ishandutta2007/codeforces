#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	cin>>a;
	while(a--){
		long long a[3];
		int b;
		cin>>a[0]>>a[1]>>a[2]>>b;
		sort(a , a+3);
		b -= a[2]-a[0]+a[2]-a[1];
		if(b < 0) cout<<"NO"<<endl;
		else if(b == 0 || b % 3 == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}