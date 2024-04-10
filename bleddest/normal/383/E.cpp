#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void zeta_transform(vector<int>& a, int n, int k)
{
	for(int i = 0; i < k; i++)
	{
		//   i           k - i
		for(int j = 0; j < n; j++)
			if((j & (1 << i)) == 0)
				a[j ^ (1 << i)] += a[j];
	}
}

int main()
{
	int n;
	cin >> n;
	int k = 24;
	int m = 1 << k;
	vector<int> a(m);
	//     ,       
	for(int i = 0; i < n; i++)
	{
	 	string s;
	 	cin >> s;
	 	int mask = 0;
	 	for(auto c : s)
	 		mask |= (1 << int(c - 'a'));
	 	a[mask]++;	
	}

	//   Z-    ,      
	zeta_transform(a, m, k);

	int res = 0;

	//        i -  n     ,   i
	for(int i = 0; i < (1 << k); i++)
	{
	 	int ans = n - a[((1 << k) - 1) ^ i];
	 	res ^= (ans * ans);
	}
	cout << res << endl;
}