#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast ios::sync_with_stdio(false), cout.tie(), cin.tie();
#define sz(s) int(s.size())

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	if ((a + b) % n == 0){
		cout << n; 
	}else if((a + b) < 0){
		cout << n + ((a + b) % n);
	}else{
		cout << (a + b) % n;
	}
}