#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dat[19] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,9,25,49 };
int main()
{
	int c = 0;
	for (int i = 0; i < 19; i++)
	{
		printf("%d\n", dat[i]); fflush(stdout);
		string s;
		cin >> s;
		if (s[0] == 'y')c++;
	}
	if (c >= 2)printf("composite\n");
	else printf("prime\n");
}