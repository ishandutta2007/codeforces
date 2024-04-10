#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int t;
	cin >> t;
	while(t--){
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		bool f = true;
		for (int i = 0; i < n; i++){
			if(a[i] == c[i] || b[i] == c[i]);else{
				f = false;
				break;
			}
		}	
		cout << (f ? "YES\n" : "NO\n");
	}
}