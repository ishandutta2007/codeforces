#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <iomanip>
//#include <ctime>
//#include <cmath>

using namespace std;

typedef long long int int64;
typedef long double double80;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	vector<string> answer;
	string st;
	string add;

	cin >> st;

	while (st[0] == '0')
	{
		st = st.substr(1, st.size());
	}

	while (st.size() != 0)
	{
		add = "";
		for (int i = 0; i < st.size(); ++i)
		{
			if (st[i] != '0')
			{
				--st[i];
				add += "1";
			}
			else
			{
				add += "0";
			}
		}

		answer.push_back(add);

		while (st.size() >0 && st[0] == '0')
		{
			st = st.substr(1, st.size());
		}
	}

	cout << answer.size() << endl;

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
	

	fclose(stdin);
	fclose(stdout);

	return 0;
}