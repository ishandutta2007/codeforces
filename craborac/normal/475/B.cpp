#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string s1, s2;
	cin >> s1;
	cin >> s2;
	bool d = 1;
	if((s1[0] == '<') && (s2[0] == '^'))
		d = 0;
	if((s1[n - 1] == '<') && (s2[0] == 'v'))
		d = 0;
	if((s1[0] == '>') && (s2[m - 1] == '^'))
		d = 0;
	if((s1[n - 1] == '>') && (s2[m - 1] == 'v'))
		d = 0;
	if(d)
		printf("YES");
	else
		printf("NO");
	return 0;
}