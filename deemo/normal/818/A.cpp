#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll rem = n/2;

	ll t = k+1;
	ll temp = rem/t;
	cout << temp << " " << temp*k << " " << n-t*temp << endl;
	return 0;
}