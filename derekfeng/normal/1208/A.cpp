#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
	cin>>T;while (T--){
		int a,b,c; cin>>a>>b>>c;c++;
		if (c%3==1) cout<<a<<"\n";
		else if (c%3==2) cout<<b<<"\n";
		else cout<<(a^b)<<"\n";
	}
}