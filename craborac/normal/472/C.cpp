#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

string mas[(int)1e5 + 20][2];
int qwe[(int)1e5 + 20];

int main()
{
	//freopen("text.in", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> mas[i][0] >> mas[i][1];
		if(mas[i][0] > mas[i][1])
		{
			string s = mas[i][0];
			mas[i][0] = mas[i][1];
			mas[i][1] = s;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cin >> qwe[i];
		qwe[i]--;
	}
	string min_s = mas[qwe[0]][0];
	for(int i = 1; i < n; i++)
	{
		string s1 = mas[qwe[i]][0];
		string s2 = mas[qwe[i]][1];
		if(s1 > min_s)
			min_s = s1;
		else if(s2 > min_s)
			min_s = s2;
		else
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}