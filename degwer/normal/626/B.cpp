#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	string s;
	cin >> s;
	int b = 0, g = 0, r = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'B')b++;
		if (s[i] == 'G')g++;
		if (s[i] == 'R')r++;
	}
	string ans;
	if (b > 0 && g > 0 && r > 0)ans = "BGR";
	else if (b == 0 && g == 0)ans = "R";
	else if (g == 0 && r == 0)ans = "B";
	else if (r == 0 && b == 0)ans = "G";
	else if ((b >= 2) + (g >= 2) + (r >= 2) >= 2)ans = "BGR";
	else if (b == 0 && g == 1 && r == 1)ans = "B";
	else if (b == 1 && g == 0 && r == 1)ans = "G";
	else if (b == 1 && g == 1 && r == 0)ans = "R";
	else if (b == 0 && g == 1)ans = "BG";
	else if (g == 0 && b == 1)ans = "BG";
	else if (b == 0 && r == 1)ans = "BR";
	else if (r == 0 && b == 1)ans = "BR";
	else if (g == 0 && r == 1)ans = "GR";
	else if (r == 0 && g == 1)ans = "GR";
	cout << ans << endl;
}