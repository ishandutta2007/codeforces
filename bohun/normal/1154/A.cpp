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
int n[4];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n[0] >> n[1] >> n[2] >> n[3];
	sort(n + 0, n + 4);
	cout << n[3] - n[0] << " " << n[3] - n[1] << " " << n[3] - n[2] << endl;
	
	
	
	
	return 0;
}