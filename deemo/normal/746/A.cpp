#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c;	cin >> a >> b >> c;
	int ans = 0;
	for (int i = 1; i <= a && i+i <= b && i*4 <= c; i++)
		ans+=7;
	cout << ans << endl;
	return 0;
}