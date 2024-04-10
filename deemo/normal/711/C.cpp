#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 100 + 5;

ll n, m, k, col[MAXN], p[MAXN][MAXN];
ll d[MAXN], c[MAXN], e[MAXN][MAXN][MAXN], sd[MAXN];

void go(ll len, ll tl, ll tr, ll ptr){
	memset(c, 63, sizeof(c));
	memset(e, 63, sizeof(e));

	e[0][tl][bool(tl)] = 0;
	for (ll i = 1; i <= len; i++)
		for (ll j = 1; j <= m; j++)
			for (ll w = 1; w <= len + 2; w++)
				for (ll z = 0; z <= m; z++)
					if (j^z)
						e[i][j][w] = min(e[i][j][w], e[i - 1][z][w - 1] + p[ptr + i - 1][j]);
					else
						e[i][j][w] = min(e[i][j][w], e[i - 1][z][w] + p[ptr + i - 1][j]);

	ll first = ll(tl != tr) + bool(tl > 0 && tr > 0);
	for (ll j = 1; j <= m; j++)
		for (ll w = 1; w <= len + 2; w++){
			ll temp = w + bool(j^tr && tr) - first;
			c[temp] = min(c[temp], e[len][j][w]);
		}

	memset(sd, 63, sizeof(sd));
	for (ll i = MAXN - 1; ~i; i--)
		for (ll j = i; ~j; j--)
			sd[i] = min(sd[i], d[i - j] + c[j]);
	memcpy(d, sd, sizeof(sd));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (ll i = 0; i < n; i++)	cin >> col[i];
	for (ll i = 0; i < n; i++)
		for (ll j = 1; j <= m; j++)	cin >> p[i][j];
	ll rem;
	{
		ll lst = -1, temp = 0;
		for (ll i = 0; i < n; i++)
			if (col[i]){
				if (~lst && lst ^ col[i])
					temp++;
				lst = col[i];
			}
		if (~lst)
			temp++;
		rem = k - temp;
	}
	if (rem < 0){
		cout << "-1\n";
		return 0;
	}
	memset(d, 63, sizeof(d));
	d[0] = 0;
	for (ll i = 0; i < n;){
		if (col[i]){
			i++;
			continue;
		}

		ll j = i;
		while (j < n && !col[j])	j++;
		go(j - i, i?col[i - 1]:0, j < n?col[j]:0, i);
		i = j;
	}
	if (d[rem] < 1e17)
		cout << d[rem] << "\n";
	else
		cout << "-1\n";
	return 0;
}