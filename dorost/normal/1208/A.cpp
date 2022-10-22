#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie(), cout.tie()

int main(){
	int t;
	cin >> t;
	while(t--){
		int a[3], n;
		cin >> a[0] >> a[1] >> n;
		a[2] = a[0] ^ a[1];
		cout << a[n % 3] << endl;
	}	
}