#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 100;
const ll MOD = 1e9 + 7;
const ll BASE1 = 701;
const ll BASE2 = 721;

ll n;
string s1, s2;
ll save1[MAXN], save2[MAXN], ss[MAXN];
bool found;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s1 >> s2;	n--;
	{
		save1[0] = save2[0] = 1;
		for (ll i = 1; i < MAXN; i++)
			save1[i] = (save1[i - 1] * BASE1) % MOD, save2[i] = (save2[i - 1] * BASE2) % MOD;

		ll h1 = 0, h2 = 0;
		for (ll i = n - 1; i >= 0; i--){
			h1 = (save1[n - i - 1] * s2[i] + h1) % MOD;
			h2 = (save2[n - i - 1] * s2[i] + h2) % MOD;
			ss[i] = (h1 << 31LL) | h2;
		}
	}

	{
		ll h1 = 0, h2 = 0;
		for (ll i = n - 1; !found && i >= 0; i--){
			char ch;
			if (s1[i] == 'W')	ch = 'E';
			if (s1[i] == 'E')	ch = 'W';
			if (s1[i] == 'N')	ch = 'S';
			if (s1[i] == 'S')	ch = 'N';

			h1 = (h1 * BASE1 + ch) % MOD;
			h2 = (h2 * BASE2 + ch) % MOD;
			
			found |= (ss[i] == ((h1 << 31) | h2));
		}	
	}

	if (!found)
		cout << "YES\n";
	else
		cout << "NO\n";
	return	0;
}