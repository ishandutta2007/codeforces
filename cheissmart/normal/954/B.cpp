#include <iostream>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	int mx = 0;
	for(int i=2;i<=n;i+=2) {
		if(s.substr(0, i/2) == s.substr(i/2, i/2)) {
			mx = max(mx, i/2);
		}
	}
	cout << ( mx ? n - mx + 1 : n) << endl;
}