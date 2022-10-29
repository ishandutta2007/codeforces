#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
bool get(int ax, int ay, int bx, int by)
{
	printf("? %d %d %d %d\n", ax + 1, ay + 1, bx + 1, by + 1), fflush(stdout);
	char s[10];
	scanf("%s", s);
	if (s[0] == 'B')exit(0);
	return s[0] == 'Y';
}
int main()
{
	int num;
	scanf("%d", &num);
	int x = 0, y = 0;
	string ans;
	for (int i = 0; i < num - 1; i++)
	{
		if (get(x, y + 1, num - 1, num - 1))ans.push_back('R'), y++;
		else ans.push_back('D'), x++;
	}
	x = num - 1, y = num - 1;
	string ra;
	for (int i = 0; i < num - 1; i++)
	{
		if (get(0, 0, x - 1, y))ra.push_back('D'), x--;
		else ra.push_back('R'), y--;
	}
	reverse(ra.begin(), ra.end());
	cout << "! " << ans + ra << endl;
	fflush(stdout);
}