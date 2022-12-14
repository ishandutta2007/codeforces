#include <cstdio>
#include <string>
using namespace std;

string sl[5][7 * 15 + 2][4 * 15 + 2];

string solve(int d, int c2, int c3)
{
	if (c2 < 0 || c3 < 0)
		return "NAN";
	if (!c2 && !c3)
	{
		return "\n";
	}
	if (d <= 1)
	{
		return "NAN";
	}
	if (sl[d][c2][c3] != "")
	{
		return sl[d][c2][c3];
	}
	string a, b;
	a = solve(d, c2 - (d/2) - (d/4) - d/8, c3 - (d/3) - (d/9));
	b = solve(d - 1, c2, c3);
	string r;
	if (a != "NAN")
	{
		a = std::string(1, '0' + d) + a;
	}
	if (a == "NAN")
		r = b;
	else if (b == "NAN")
		r = a;
	else
	{
		if (a.size() < b.size())
			r = b;
		else if (a.size() > b.size())
			r = a;
		else
		{
			if (a > b)
				r = a;
			else r = b;
		}
	}
	
	return (sl[d][c2][c3] = r);
}

int main()
{
	int n;
	char a[32];
	
	scanf("%d", &n);
	scanf("%s", a);
	int c2, c3, c5, c7;
	
	c2 = c3 = c5 = c7 = 0;
	for (int i = 0; i < n; ++i)
	{
		int x = a[i] - '0';
		c2 += (x / 2) + (x / 4) + (x / 8);
		c3 += (x / 3) + (x / 9);
		c5 += (x / 5);
		c7 += (x / 7);
	}
	
	string sl = "NAN";
	for (int n9 = 0; n9 <= c7; ++n9)
	{
		for (int n8 = 0; n8 + n9 <= c7; ++n8)
		{
			int n7 = c7 - n8 - n9;
			for (int n6 = 0; n6 <= c5 - c7; ++n6)
			{
				int n5 = c5 - c7 - n6;
				int nc2, nc3;
				nc2 = c2 - (n7 + n6) * 4 - (n8 + n9) * 7 - n5 * 3;
				nc3 = c3 - n9 * 4 - (n6 + n7 + n8) * 2 - n5;
				string os = solve(4, nc2, nc3);
				if (os == "NAN")
					continue;
				os = std::string(n9, '9') + std::string(n8, '8') + std::string(n7, '7') + std::string(n6, '6') + std::string(n5, '5') + os;
				if (sl == "NAN")
				{
					sl = os;
					continue;
				}
				if (os.size() > sl.size())
					sl = os;
				else if (os.size() == sl.size() && os > sl)
					sl = os;
			}
		}
	}
	
	printf("%s", sl.c_str());
	return 0;
}