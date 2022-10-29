#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
#include<bitset>
using namespace std;
int imos[4][200001];
bitset<200000>bi[4];
int get(char a)
{
	if (a == 'A')return 0;
	if (a == 'C')return 1;
	if (a == 'G')return 2;
	return 3;
}
int main()
{
	int ns, nt, gen;
	scanf("%d%d%d", &ns, &nt, &gen);
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < s.size(); i++)
	{
		int x = get(s[i]);
		imos[x][max(0, i - gen)]++;
		imos[x][min(ns, i + gen + 1)]--;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < s.size(); j++)imos[i][j + 1] += imos[i][j];
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < s.size(); j++)if (imos[i][j])bi[i][j] = true;
		//for (int j = 0; j < s.size(); j++)printf("%d", int(imos[i][j] != 0)); printf("\n");
	}
	bitset<200000>now;
	for (int i = 0; i < s.size(); i++)now[i] = true;
	for (int i = 0; i < t.size(); i++)
	{
		int x = get(t[i]);
		now &= (bi[x]) >> i;
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)if (now[i])cnt++;
	printf("%d\n", cnt);
}