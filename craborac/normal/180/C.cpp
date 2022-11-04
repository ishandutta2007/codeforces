#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int mas[(int)1e5 + 20][2];

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	mas[0][0] = 0;
	if(s[0] <= 'Z')
		mas[0][0]++;
	mas[0][1] = 0;
	if(s[0] >= 'a')
		mas[0][1]++;
	for(int i = 1; i < n; i++)
	{
		mas[i][1] = mas[i - 1][1];
		if(s[i] >= 'a')
			mas[i][1]++;
		mas[i][0] = min(mas[i - 1][0], mas[i - 1][1]);
		if(s[i] <= 'Z')
			mas[i][0]++;
	}
	printf("%d", min(mas[n - 1][0], mas[n - 1][1]));
	return 0;
}