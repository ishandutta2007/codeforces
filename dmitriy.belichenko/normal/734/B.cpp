#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long ans;
	int  k2, k3, k5, k6;
	cin >>  k2 >> k3 >> k5 >> k6;
	int a = min(k2, min(k5, k6));
	int b = max(0,min(k2 - a, k3));
	ans = a * 256 + b * 32;
	cout << ans;
}