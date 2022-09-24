#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{

	string s, a = "", b = "", d = "";
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.' or s[i] == 'e') cnt++;
		else if (cnt == 0) a += s[i];
		else if (cnt == 1) d += s[i];
		else b += s[i];
	}
	string ans = a + d;
	if (d == "0" and b == "0") cout << a << "\n";
	else if (d.size() <= atoi(b.c_str())) cout << ans + string(atoi(b.c_str()) - d.size(), '0') << "\n";
	else
	{
		ans.insert(atoi(b.c_str()) + 1, ".");
		cout << ans << "\n";
	}

	return 0;
}