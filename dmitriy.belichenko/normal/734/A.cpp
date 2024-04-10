#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A') a++;
		if (s[i] == 'D')b++;
	}
	if (a > b) cout << "Anton";
	if (a < b) cout << "Danik";
	if (a == b) cout << "Friendship";
}