#include <stdio.h>
#include <utility>
#include <string>
#include <vector>
#include <iostream>
#define MAX(a, b)	(((a) > (b)) ? (a) : (b))

using namespace std;

int N;
string s[100005];
int length[100005];
vector<int> event[2000005];
string ans;

int main()
{
	scanf("%d", &N);

	int final_length = -1;

	for(int i = 0; i < N; i++)
	{
		cin >> s[i];
		length[i] = s[i].size();

		int k;
		scanf("%d", &k);
		
		for(int j = 0; j < k; j++)
		{
			int b;
			scanf("%d", &b);
			b--;

			event[b].push_back(i);
			final_length = MAX(final_length, length[i] + b - 1);
		}
	}

	int maxend = -1, max_str = 0, cnt = 0;

	for(int i = 0; i <= final_length; i++)
	{
		for(int j = 0; j < event[i].size(); j++)
		{
			if(maxend < i + length[event[i][j]] - 1)
			{
				maxend = i + length[event[i][j]] - 1;
				max_str = event[i][j];
				cnt = 0;
			}
		}

		if(cnt >= length[max_str] || maxend == -1)
		{
			ans.push_back('a');
			continue;
		}
		else
		{
			ans.push_back(s[max_str][cnt++]);
		}
	}

	cout << ans;
	return 0;
}