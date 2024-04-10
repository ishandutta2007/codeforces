#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int n;
	string t;
	cin >> n >>  t;
	if (t.size() > n)
		cout << -1;
	else{
		cout << t;
		for (int i = 0; i < n - t.size(); i++){
			cout << 0;
		}
	}
}