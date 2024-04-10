#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = (c + min(a, b)) * 2;
	if(a == b){
		cout << ans;
	}else{
		cout << ans + 1;
	}
}