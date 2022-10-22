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
const int nax = 500005, mod = 998244353;
const ll inf = 1e18;

int n;
string ss;
stack <int> s;
int col[nax];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int last = -1;
	int bil = 0;
	cin >> n >> ss;
	ss = '2' + ss;
	int K = 0;
	for(int i = 1; n >= i; ++i)
	{
		if(ss[i] == '(')
		{
			++bil;
			s.push(i);
		}
		else
		{
			if(s.top() < last)
				K ^= 1;
			--bil;
			col[i] = s.size();
			col[s.top()] = s.size();
			s.pop();
			last = i;
		}
	}
	for(int i = 1; n >= i; ++i)
		cout << col[i] % 2;
				
		
		
		
	
    return 0;
}