#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;	long long k;	cin >> n >> k;
	cout << __builtin_ctzll(k)+1 << endl;
	return 0;
}