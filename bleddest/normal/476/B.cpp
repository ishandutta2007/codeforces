#include <iostream>
#include <iomanip>
using namespace std;

string s1, s2;
int finish_pos;
double ans = 0.0;

void rec(int i, int pos, double p)
{
	if (i == s2.size())
	{
		if (pos == finish_pos)
			ans += p;
	}
	else
	{
		char c = s2[i];
		if (c == '+')
			rec(i + 1, pos + 1, p);
		else if (c == '-')
			rec(i + 1, pos - 1, p);
		else
		{
			rec(i + 1, pos + 1, p * 0.5);
			rec(i + 1, pos - 1, p * 0.5);
		}
	}
}

int main() {
	cin >> s1 >> s2;
	finish_pos = 0;
	for (auto x : s1)
		if (x == '+')
			finish_pos++;
		else
			finish_pos--;
	rec(0, 0, 1.0);
	cout << setprecision(15) << fixed;
	cout << ans << endl;
	return 0;
}