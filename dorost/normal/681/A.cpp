#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, a, b;
	cin >> n;
	string s;
	bool p = false;
	for(int i = 0; i < n; i++){
		cin >> s >> a >> b;
		if(a >= 2400 && b > a){
			p = true;
		}
	}
	cout << ((p) ? "YES" : "NO");
}