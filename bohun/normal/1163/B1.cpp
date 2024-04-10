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
int n;
int t[nax];
int ile[nax];
int col[nax];
set <int> s;
int x = 1;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; n > i; ++i)
	{
		cin >> t[i];
		if(col[t[i]])
		{
			ile[col[t[i]]]--;
			if(ile[col[t[i]]] == 0)
				s.erase(col[t[i]]);
		}
		col[t[i]]++;
		ile[col[t[i]]]++;
		if(ile[col[t[i]]] == 1)
		{
			s.insert(col[t[i]]);
		}
		if(ss(s) > 2)
			continue;
		if(col[t[i]] == i + 1)
			x = i + 1;
		if(ss(s) == 1 && *s.begin() == 1)
			x = i + 1;
		if(ss(s) == 2)
		{
			int kon = *--s.end();
			int pocz = *s.begin();
			if(pocz == 1 && ile[pocz] == 1)
				x = i + 1;
			if(ile[kon] == 1 && kon == pocz + 1)
				x = i + 1;
		}
		
	}
	cout << x;
	
		
		
	
				
    return 0;
}