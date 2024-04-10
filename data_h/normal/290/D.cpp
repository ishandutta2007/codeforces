#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 2000;

string str, opt;
int n;

int main()
{
	int n;
	opt.clear();
	str.clear();
	cin >> str;
	scanf("%d", &n);
	for(int i = 0; i < str.length(); i++)
	{
		if (str[i] > 'z' || str[i] < 'a')
			str[i] = str[i] - 'A' + 'a';
	}
	for(int i = 0; i < str.length(); i++)
	{
		char tmp = str[i];
		if ((int)tmp < (int)n + 97)
		{
			tmp = tmp - 'a' + 'A';
			opt = opt + tmp;
		} else
		{
			opt = opt + tmp;
		}
	}
	cout << opt << endl;
	return 0;
}