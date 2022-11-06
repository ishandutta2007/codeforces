#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
int app[128]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("725C.in", "r", stdin); 
#endif
	string str; 
	cin >> str; 
	string ans[2]; 
	ans[0].resize(13); 
	ans[1].resize(13); 
	memset(app, -1, sizeof(app)); 
	bool f = false; 
	int fst, lst; 
	for (int i = 0; i < str.size(); i++)
	{
		if (app[str[i]] != -1)
		{
			f = true; 
			lst = i; 
			fst = app[str[i]]; 
		}
		app[str[i]] = i; 
	}
	if (lst == fst + 1)
	{
		printf("Impossible\n");
		return 0; 
	}
	if ((lst - fst) & 1)
	{
		// cout << fst << " " << lst << endl; 
		for (int i = lst - fst >> 1; i >= 0; i--)
			ans[1][i] = str[fst + (lst - fst >> 1) - i]; 
		for (int i = (lst - fst >> 1) - 1; i >= 0; i--)
			ans[0][i] = str[fst + (lst - fst >> 1) + i + 1]; 
		// cout << ans[0] << endl << ans[1] << endl; 
		int curx = 1, cury = (lst - fst >> 1) + 1;
		for (int i = fst - 1; i >= 0; i--)
		{
			if (cury >= 13)
			{
				curx ^= 1; 
				cury = 12; 
			}
			ans[curx][cury] = str[i]; 
			cury += curx ? 1 : -1; 
			if (cury >= 13)
			{
				curx ^= 1; 
				cury = 12; 
			}
		}
		curx = 0; 
		cury = (lst - fst >> 1); 
		for (int i = lst + 1; i < str.size(); i++)
		{
			if (cury >= 13)
			{
				curx ^= 1; 
				cury = 12; 
			}
			ans[curx][cury] = str[i]; 
			cury += curx ? -1 : 1; 
			if (cury >= 13)
			{
				curx ^= 1; 
				cury = 12; 
			}
		}
		cout << ans[0] << endl << ans[1] << endl; 
	}
	else
	{
		// cout << fst << " " << lst << endl; 
		for (int i = (lst - fst >> 1) - 1; i >= 0; i--)
			ans[1][i] = str[fst + (lst - fst >> 1) - i]; 
		for (int i = (lst - fst >> 1) - 1; i >= 0; i--)
			ans[0][i] = str[fst + (lst - fst >> 1) + i + 1]; 
		// cout << ans[0] << endl << ans[1] << endl; 
		int curx = 0, cury = lst - fst >> 1;
		for (int i = fst - 1; i >= 0; i--)
		{
			ans[curx][cury] = str[i]; 
			cury += curx ? -1 : 1; 
			if (cury >= 13)
			{
				curx ^= 1; 
				cury = 12; 
			}
		}
		curx = 1; 
		cury = (lst - fst >> 1); 
		for (int i = lst + 1; i < str.size(); i++)
		{
			ans[curx][cury] = str[i]; 
			cury += curx ? 1 : -1; 
			if (cury >= 13)
			{
				curx ^= 1; 
				cury = 12; 
			}
		}
		cout << ans[0] << endl << ans[1] << endl; 
	}
	return 0; 
}