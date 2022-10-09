#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

int main() {
	string s, t;
	cin >> s >> t;
	int n;
	cin >> n;
	cout << s << " " << t << endl;
	for(int i = 0; i < n; i++)
	{
	 	string a, b;
	 	cin >> a >> b;
	 	if (s == a)
	 		swap(s, b);
	  	else swap(t, b);
	  	cout << s << " " << t << endl;
	}
	return 0;
}