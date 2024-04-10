#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define ss(x) (int) x.size()
using namespace std;
int n, t[1000005][2], id[1000005];
ll sum[1000005][2];
vector <int> v[1000005];
int main()
{	
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int j = 0; 2 > j; ++j)
		for(int i = 1; n >= i; ++i)
			cin >> t[i][j], sum[i][j] = sum[i - 1][j] + t[i][j];
	int lewo = 0;
	bool h = 0;
	if(sum[n][0] > sum[n][1])
		h = 1;
	if(sum[n][0] > sum[n][1])
		for(int i = 1; n >= i; ++i)
		{
			swap(sum[i][0], sum[i][1]);
		}
	for(int i = 1; n >= i; ++i)
	{
		while(lewo + 1 <= n && sum[lewo + 1][1] <= sum[i][0])
			++lewo;
		id[i] = lewo;
		assert(sum[i][0] - sum[lewo][1] >= 0);
		v[sum[i][0] - sum[lewo][1]].pb(i);
	}
	v[0].pb(0);
	int i = 0;
	while(4 > 3)
	{
		if(ss(v[i]) >= 2)
		{
			int A = v[i][0];
			int B = v[i][1];
			if(A > B)
				swap(A, B);
			if(h == 1)
			{
				cout << id[B] - id[A] << "\n";
				for(int j = id[B]; j >= id[A] + 1; --j)
					cout << j << " ";
				cout << "\n";
			}
			cout << B - A << "\n";
			for(int j = B; j >= A + 1; --j)
				cout << j << " ";
			cout << "\n";
			if(h == 0)
			{
				cout << id[B] - id[A] << "\n";
				for(int j = id[B]; j >= id[A] + 1; --j)
					cout << j << " ";
			}
			exit(0);
		}
		++i;
	}
	return 0;
}