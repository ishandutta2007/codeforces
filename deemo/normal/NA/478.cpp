#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c; cin >> n >> c;
	while (c--){
		if (n % 10)
			n--;
		else
			n /= 10;
	}
	cout << n << endl;
	return 0;
}