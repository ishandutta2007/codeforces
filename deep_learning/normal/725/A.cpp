#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
bool forever[204800]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("725A.in", "r", stdin); 
	freopen("725A.out", "wt", stdout); 
#endif
	int n; 
	scanf("%d", &n); 
	string str; 
	cin >> str; 
	for (int i = 0; i < n - 1; i++)
	{
		if (str[i] == '>' && str[i + 1] == '<')
		{
			forever[i] = true; 
			forever[i + 1] = true; 
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '<' && i)
			forever[i] |= forever[i - 1]; 
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] == '>' && i + 1 != n)
			forever[i] |= forever[i + 1]; 
	}
	int ans = 0; 
	for (int i = 0; i < n; i++)
		ans += !forever[i]; 
	printf("%d\n", ans);
	return 0; 
}