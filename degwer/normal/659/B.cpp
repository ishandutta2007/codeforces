#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef pair<int, string>pis;
vector<pis>dat[10000];
int main()
{
	int num, re;
	scanf("%d%d", &num, &re);
	for (int i = 0; i < num; i++)
	{
		string z;
		cin >> z;
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		dat[za].push_back(make_pair(zb, z));
	}
	for (int i = 0; i < re; i++)
	{
		sort(dat[i].begin(), dat[i].end());
		reverse(dat[i].begin(), dat[i].end());
		if (dat[i].size() == 2)cout << dat[i][0].second << " " << dat[i][1].second << endl;
		else if(dat[i][1].first!=dat[i][2].first)cout << dat[i][0].second << " " << dat[i][1].second << endl;
		else cout << "?" << endl;
	}
}