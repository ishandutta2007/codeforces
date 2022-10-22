#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, m, a, b, c, t[200005];
int id[200005];
pair < int, int> naj[2];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; n >= i; ++i)
		scanf("%d", &t[i]);
	for(int i = 1; n >= i; ++i)
	{
		if(naj[0].fi == t[i])
			id[i] = naj[1].se;
		else
			id[i] = naj[0].se;
		if(t[i] != naj[0].fi)
			swap(naj[0], naj[1]);
		naj[0] = {t[i], i};
	}
	for(int i = 1; m >= i; ++i)
	{
		scanf("%d %d %d", &a, &b, &c);
		if(t[b] != c)
			cout << b << endl;
		else{
			if(id[b] < a)
				cout << -1 << endl;
			else
				cout << id[b] << endl;
			}
	}
		
	return 0;
}