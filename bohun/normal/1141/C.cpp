#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n;
int q[200005], t[200005];
int id = 1, naj = 0;
int bylo[200005];
int main()
{
	cin >> n;
	for(int i = 2; n >= i; ++i)
		cin >> q[i];
	int sum = 0;
	bylo[0] = 1;
	for(int i = 2; n >= i; ++i)
	{
		sum += q[i];
		if(sum >= naj)
			{
				naj = sum;
				id = i;
			}
	}
	t[id] = n;
	for(int i = 1; n >= i; ++i)
		bylo[i] = 0;
	for(int j = id + 1; n >= j; ++j)
		t[j] = t[j - 1] + q[j];
	for(int j = id - 1; j >= 1; --j)
		t[j] = t[j + 1] - q[j + 1];
	for(int i = 1; n >= i; ++i)
	{
		if(t[i] < 1 or t[i] > n or bylo[t[i]])
			{
				cout << -1;
				exit(0);
			}
		bylo[t[i]] = 1;
	}
	for(int i = 1; n >= i; ++i)
		cout << t[i] << " ";
	return 0;
}