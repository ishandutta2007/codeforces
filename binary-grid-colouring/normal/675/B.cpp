#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,b,c,d; 
	cin >> n >> a >> b >> c >> d;
	cout << max(n*(n-abs(b-c)-abs(a-d)), 0ll) << endl;
}