#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll; 
int off[] = {4, 5, 6, 3, 2, 1}; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("725B.in", "r", stdin); 
#endif
	string str; 
	cin >> str; 
	stringstream ss(str); 
	ll num; 
	char s; 
	ss >> num >> s; 
	if (num % 4 <= 2 && num % 4)
		printf("%lld\n", (num / 4 * 2 + num % 4 - 1) * 6 + num - 1 + off[s - 'a']);
	else
		printf("%lld\n", (num / 4 * 2 + num % 4 - 3 + (num % 4 == 0) * 2) * 6 + num - 3 + off[s - 'a']);
	return 0; 
}