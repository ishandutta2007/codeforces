#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	if (n&1)
		cout << "contest\n";
	else
		cout << "home\n";
	return 0;
}