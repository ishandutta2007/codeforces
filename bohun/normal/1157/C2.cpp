#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define fo(i, n) for(int i = 0; n > i; ++i)
using namespace std;

const int nax = 200005, mod = 1e9 + 7;
const int inf = 1e9;

int n;
int t[nax];			
		
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	fo(i, n)
		cin >> t[i];
	vector <int> a, b;
	int last = t[0];
	int ile = 1;
	int lewo = 1;
	int prawo = n - 1;
	a.pb(0);
	while(prawo >= lewo)
	{
		if(t[lewo] <= last && t[prawo] <= last)
			break;
		if(t[lewo] == t[prawo])
		{
			int L = last;
			int lewoo = 0;
			int le = lewo;
			while(last < t[lewo] && lewo <= prawo)
			{
				lewoo++;
				last = t[lewo++];
			}
			last = L;
			int prawoo = 0;
			while(last < t[prawo] && prawo >= le)
			{
				prawoo++;
				last = t[prawo--];
			}
			if(lewoo >= prawoo)
			{
				while(lewoo--)
					a.pb(0);
			}
			else
			{
				while(prawoo--)
					a.pb(1);
			}
			break;
		}
				
		if(t[prawo] <= last || (t[lewo] < t[prawo] && t[lewo] > last))
		{
			last = t[lewo];
			++ile;
			++lewo;
			a.pb(0);
		}
		else
		{
			last = t[prawo];
			++ile;
			--prawo;
			a.pb(1);
		}
	}
	b.pb(1);
	lewo = 0;
	prawo = n - 2;
	ile = 1;
	last = t[n - 1];
	while(prawo >= lewo)
	{
		if(t[lewo] <= last && t[prawo] <= last)
			break;
		if(t[lewo] == t[prawo])
		{
			int L = last;
			int lewoo = 0;
			int le = lewo;
			while(last < t[lewo] && lewo <= prawo)
			{
				lewoo++;
				last = t[lewo++];
			}
			last = L;
			int prawoo = 0;
			while(last < t[prawo] && prawo >= le)
			{
				prawoo++;
				last = t[prawo--];
			}
			if(lewoo >= prawoo)
			{
				while(lewoo--)
					b.pb(0);
			}
			else
			{
				while(prawoo--)
					b.pb(1);
			}
			break;
		}
				
		if(t[prawo] <= last || (t[lewo] < t[prawo] && t[lewo] > last))
		{
			last = t[lewo];
			++ile;
			++lewo;
			b.pb(0);
		}
		else
		{
			last = t[prawo];
			++ile;
			--prawo;
			b.pb(1);
		}
	}
	if(ss(a) >= ss(b))
	{
		swap(a, b);
	}
	cout << ss(b) << endl;
	for(auto it: b)
	{
		cout << (it == 0 ? "L" : "R");
	}
	
	
	
	
	return 0;
}