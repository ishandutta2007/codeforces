#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define For(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 100005, pod = (1 << 17);

int n, k;
int t[nax];


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	cin >> k;
	if(k <= 1)
	{
		cout << 1;
		return 0;
	}
	for(int i = 0; n > i; i += 2)
	{
		t[i] = 1;
		k--;
		if(!k)
			break;
	}
	int j = 1;
	while(n > j && k)
	{
		t[j] = 1;
		k--;
		j += 2;
	}
	int ile = 0;
	if(t[0] == t[n - 1] && t[0] == 0)
		ile--;
	int last = 1;
	for(int i = 0; n > i; ++i)
	{
		if(last == 1 && t[i] == 0)
			ile++;
		last = t[i];
	}
	cout << ile;
		
	
		
	
				
    return 0;
}