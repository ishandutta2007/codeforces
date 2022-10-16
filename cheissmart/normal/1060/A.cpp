#include <iostream>

using namespace std;

int main()
{
	int n, ct = 0;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++)
		if(s[i] == '8')
			ct++;
	cout << min(ct, n/11) << endl;
}