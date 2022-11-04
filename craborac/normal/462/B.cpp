#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>

using namespace std;

int mas[30];

int main()
{
	int n, k;
	string s;
	scanf("%d%d", &n, &k);
	cin >> s;
	for(int i = 0; i < 26; i++)
		mas[i] = 0;
	for (int i = 0; i < n; i++)
	{
		mas[s[i] - 'A']++;
	}
	sort(mas, mas + 26);
	int col = 0;
	int ind = 25;
	long long ans = 0;
	while(col < k)
	{
		int q = min(mas[ind], k - col);
		ind--;
		ans += (long long)q * q;
		col += q;
	}
	cout << ans;
	return 0;
}