#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std; 
typedef long long ll; 
string name[5120], v1[5120], op[5120], v2[5120], ans1, ans2; 
map<string, int> num; 
int n1[5120], n2[5120], val[5120]; 
int calc(int a, string x, int b)
{
	if (x == "XOR")
		return a ^ b; 
	if (x == "OR")
		return a | b; 
	return a & b; 
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("778B.in", "r", stdin); 
#endif
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	int n, m; 
	cin >> n >> m; 
	ans1.resize(m); 
	ans2.resize(m); 
	for (int i = 0; i < n; i++)
	{
		cin >> name[i] >> v1[i] >> v1[i]; 
		if (!isdigit(v1[i][0]))
			cin >> op[i] >> v2[i]; 
		num[name[i]] = i; 
	}
	for (int j = 0; j < m; j++)
	{
		int tot1 = 0, tot2 = 0; 
		for (int i = 0; i < n; i++)
		{
			if (isdigit(v1[i][0]))
			{
				val[i] = v1[i][j] - '0'; 
				tot1 += val[i]; 
				continue; 
			}
			if (isalpha(v1[i][0]))
				n1[i] = val[num[v1[i]]]; 
			else
				n1[i] = 0; 
			if (isalpha(v2[i][0]))
				n2[i] = val[num[v2[i]]]; 
			else
				n2[i] = 0; 
			val[i] = calc(n1[i], op[i], n2[i]); 
			tot1 += val[i]; 
		}
		for (int i = 0; i < n; i++)
		{
			if (isdigit(v1[i][0]))
			{
				val[i] = v1[i][j] - '0'; 
				tot2 += val[i]; 
				continue; 
			}
			if (isalpha(v1[i][0]))
				n1[i] = val[num[v1[i]]]; 
			else
				n1[i] = 1; 
			if (isalpha(v2[i][0]))
				n2[i] = val[num[v2[i]]]; 
			else
				n2[i] = 1; 
			val[i] = calc(n1[i], op[i], n2[i]); 
			tot2 += val[i]; 
		}
		if (tot1 > tot2)
		{
			ans1[j] = '1'; 
			ans2[j] = '0'; 
		}
		else if (tot1 == tot2)
		{
			ans1[j] = '0'; 
			ans2[j] = '0'; 
		}
		else
		{
			ans1[j] = '0'; 
			ans2[j] = '1';
		}
	}
	cout << ans1 << endl << ans2 << endl; 
	return 0; 
}