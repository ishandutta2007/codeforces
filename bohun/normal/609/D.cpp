#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, k, m, s, prze[200005][2], d[200005][2];
vector <int> v[2];
ll pref[200005][2];
int id1, id2;
int opt = - 1;
bool fun(int x)
{
	v[0].clear(), v[1].clear();
	int A = 1e9;
	int B = 1e9;
	
	for(int i = 1; x >= i; ++i)
		{
			if(A > prze[i][0])
				id1 = i;
			if(B > prze[i][1])
				id2 = i;
			A = min(A, prze[i][0]), B = min(B, prze[i][1]);
		}
		
	for(int i = 1; m >= i; ++i)
	{
		v[d[i][0]].pb(d[i][1]);
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	for(int i = 0; 2 > i; ++i)
		for(int j = 0; ss(v[i]) > j; ++j)
			pref[j + 1][i] = v[i][j] + pref[j][i];
	for(int i = 0; k >= i; ++i)
	{
		if(ss(v[0]) < i || ss(v[1]) < k - i)
			continue;
		ll need = pref[i][0] * A + pref[k - i][1] * B;
		if(need <= s)
			{
				opt = i;
				return 1;
			}
	}
	return 0;
}
int main()
{
	scanf("%d %d %d %d", &n ,&m, &k, &s);
	for(int j = 0; 2 > j; ++j)
		for(int i = 1; n >= i; ++i)
			scanf("%d", &prze[i][j]);
	for(int i = 1; m >= i; ++i)
		for(int j = 0; 2 > j; ++j)
			{
				scanf("%d", &d[i][j]);
				if(j == 0)
					d[i][j]--;	
			}
	int lewo = 1;
	int prawo = n + 1;
	while(prawo > lewo)
	{
		int mid = (lewo + prawo) / 2;
		if(fun(mid) == 1)
			prawo = mid;
		else
			lewo = mid + 1;
	}
	if(prawo == n + 1)
		cout << "-1\n";
	else
		{
			cout << lewo << endl;
			fun(lewo);
			vector < pair <int, int > > r[2];
			for(int i = 1; m >= i; ++i)
				r[d[i][0]].pb({d[i][1], i});
			sort(r[0].begin(), r[0].end());
			sort(r[1].begin(), r[1].end());
			for(int i = 0; opt > i; ++i)
				cout << r[0][i].se << " " << id1 << endl;
			for(int i = 0; k - opt > i; ++i)
				cout << r[1][i].se << " " << id2 << endl;
		}
	return 0;
}