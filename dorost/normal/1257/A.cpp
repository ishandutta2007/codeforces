#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t,n,s,a,b,m;
	cin >> t;
	while (t--) {
		cin >> n >> s >> a >> b;
		if(a > b){
			swap(a, b);
		}
		m = n - b + a;
		if(m > s){
			cout << s + b - a << endl;
		}else{
			cout << n - 1 << endl;
		}
	}
}