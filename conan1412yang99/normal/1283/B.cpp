#include <bits/stdc++.h>

using namespace std;

int main(){
	int a;
	cin>>a;
	while(a--){
		int b , c , d , e , ans = 0;
		cin>>b>>c;
		d = b / c;
		ans = c * d;
		e = b % c;
		if(e != 0){
			int k = c / 2;
			if(e >= k) ans += k;
			else ans += e;
		}
		cout<<ans<<endl;
	}
}