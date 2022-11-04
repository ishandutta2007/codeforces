#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int n;
	string s;
	scanf("%d", &n);
	cin >> s;	
	int ans = 1;
	int q = 0;
	while((q < n) && (s[q] == '1'))
	{
		q++;
		ans++;
	}
	if(ans > n)
		ans = n;
	printf("%d", ans);
	return 0;
}