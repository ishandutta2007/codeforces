#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	cin>>a;
	while(a--){
		long long b[3];
		cin>>b[0]>>b[1]>>b[2];
		sort(b , b+3);
		int ans = (b[2] - b[0] - 2)*2;
		if(ans < 0) ans = 0;
		cout<<ans<<endl;
	}
}