#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	if (n % 2 == 1)
		cout << (n / 2) - n << endl;
	else
		cout << n / 2 << endl;
}