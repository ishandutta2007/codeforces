#include <iostream>

using namespace std;

int main()
{
	int n, ans = 0;
	bool ok = true;
	string s;
	cin >> n >> s;
	for(int i=0;i<n-2;) {
		int l = 1;
		if(s[i] != 'x') {
			i++;
			continue;
		}
		while(s[++i] == 'x') l++;
		ans += max(l - 2, 0);
	}
	cout << ans << endl;
}