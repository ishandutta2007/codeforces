#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 100005;

int n, t;
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> t;
	int naj = 1000000000, id = -1;
	for(int i = 1; n >= i; ++i)
	{
		int a, b;
		cin >> a >> b;
		int w = ceil((double)(t - a) / b);
		if(a >= t && naj > a)
		{
			id = i;
			naj = a;
		}
		if(w >= 0 && a + w * b < naj)
		{
			id = i;
			naj = a + w * b;
		}
	}
	cout << id;
		
	
	
	
	
	
	
	
	// fflush(stdout)
	return 0;
}