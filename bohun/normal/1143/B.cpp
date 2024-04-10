#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
int n, len;
int t[nax];
vector <int> v;
int naj = 0;
int pot(int a, int b)
{
	if(b == 0)
		return 1;
	return a * pot(a, b - 1);
}
void rek(int poz, int kon, int val)
{
	if(poz == kon)
	{
		naj = max(naj, val);
		return ;
	}
	if(v[poz] == 0)
		return;
	naj = max(naj, val * (v[poz] - 1) * pot(9, len - poz - 1));
	rek(poz + 1, kon, val * v[poz]);
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	int x = n;
	while(x)
	{
		len++;
		v.pb(x % 10);
		x /= 10;
	}
	reverse(v.begin(), v.end());
	rek(0, ss(v), 1);
	if(len >= 2 && v[0] == 1)
		naj = max(naj, pot(9, len - 1));
	cout << naj;
	
	return 0;
}