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

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

vector<string> answer;
bool used[256];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	string st;

	cin >> n;
	cin >> st;

	int count = 1;

	string now;

	for (int i = 'a'; i <= 'z'; ++i)
	{
		used[i] = false;
	}

	now = st[0];

	used[st[0]] = true;

	for (int i = 1; i < st.size(); ++i)
	{
		if (!used[st[i]] && count < n)
		{
			++count;
			answer.push_back(now);

			now = st[i];
			used[st[i]] = true;
		}
		else
		{
			now += st[i];
		}
	}

	answer.push_back(now);

	if (count < n)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES\n";

		for (int i = 0; i < n; ++i)
		{
			cout << answer[i] << "\n";
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}