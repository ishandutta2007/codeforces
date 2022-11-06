#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define pb push_back
using namespace std; 
int main()
{
	// freopen("738D.in", "r", stdin); 
	ios::sync_with_stdio(false); 
	cin.tie(0); 
	cout.tie(0); 
	vector<int> ans; 
	int n, a, b, k, cnt = 0, tot = 0; 
	cin >> n >> a >> b >> k; 
	string str; 
	cin >> str; 
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '0')
		{
			cnt++; 
			if (cnt == b)
			{
				cnt = 0; 
				tot++; 
				if (tot >= a)
				{
					ans.pb(i); 
					tot--; 
				}
			}
		}
		else
			cnt = 0; 
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << " "; 
	return 0; 
}