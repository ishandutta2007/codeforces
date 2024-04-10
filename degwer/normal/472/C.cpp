#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
string dat[100000][2];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		string sa, sb;
		cin >> sa >> sb;
		dat[i][0] = min(sa, sb), dat[i][1] = max(sa, sb);
	}
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z - 1);
	}
	string now = "";
	bool f = true;
	for (int i = 0; i < num; i++)
	{
		if (now < dat[v[i]][0])now = dat[v[i]][0];
		else if (now < dat[v[i]][1])now = dat[v[i]][1];
		else f = false;
	}
	if (f)printf("YES\n");
	else printf("NO\n");
}