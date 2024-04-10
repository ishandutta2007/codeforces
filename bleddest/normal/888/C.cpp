#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

string s;
int n;

bool can(int x)
{
	for(char c = 'a'; c <= 'z'; c++)
	{
		bool good = true;
		int cnt = 0;
		for(int i = 0; i < x; i++)
			if(s[i] == c)
				cnt++;
		if(cnt == 0)
			good = false;
		for(int i = 0; i < n - x; i++)
		{
			if(s[i] == c)
				cnt--;
			if(s[i + x] == c)
				cnt++;
			if(cnt == 0)
				good = false;
		}
		if(good)
			return true;
	}
	return false;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	n = s.size();
	int lf = 0;
	int rg = n;
	while(rg - lf > 1)
	{
		int mid = (lf + rg) / 2;
		if(can(mid))
			rg = mid;
		else
			lf = mid;
	}
	cout << rg << endl;
}