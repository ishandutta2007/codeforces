#include <iostream>

using namespace std;

int f[1005];

int main()
{
	int n;
	f[1] = 1;
	f[2] = 1;
	for(int i=3;i<1005;i++) {
		f[i] = f[i-1] + f[i-2];
	}
	cin >> n;
	string s = "";
	for(int i=0;i<n;i++) s += 'o';
	for(int i=1;f[i] <= n;i++) s[f[i]-1] = 'O';
	cout << s << endl;
}