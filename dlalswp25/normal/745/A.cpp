#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> ans;

int main()
{
	string s;
	cin >> s;

	ans.push_back(s);

	int sz = s.size();
	for(int i = 0; i < sz - 1; i++)
	{
		string news;
		news.push_back(s[sz - 1]);
		for(int j = 0; j < sz - 1; j++)	news.push_back(s[j]);

		bool canPut = true;
		for(int j = 0; j < ans.size(); j++)
		{
			bool allSame = true;
			for(int k = 0; k < sz; k++)
			{
				if(news[k] != ans[j][k])	allSame = false;
			}
			if(allSame)	canPut = false;
		}
		if(canPut)	ans.push_back(news);
		for(int j = 0; j < sz; j++)	s[j] = news[j];
	}
	printf("%d\n", ans.size());
	return 0;
}